//Robinson-Schensted-Knuth Algorithm
int LIS(vector<int>& nums){

    int array_length = nums.size();
    vector<int> t;             //record current increasing sequence

    if(array_length == 0)
        return(0);

    t.push_back(nums[0]);
    for(int i=1 ; i<array_length ; i++){
        //directly add to current increasing sequence
        if(nums[i] > t.back()){
            t.push_back(nums[i]);
        }
        else{
            auto it = lower_bound(t.begin(), t.end(), nums[i]);
            *it = nums[i];
        }
    }
    return(t.size());
}