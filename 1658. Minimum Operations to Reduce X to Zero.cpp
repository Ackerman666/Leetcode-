class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int vclen = nums.size() , vcsum = 0 ;

        for(int i=0 ; i<vclen ; i++){
            vcsum += nums[i];
        }

        if(vcsum == x) return(vclen);

        else if(vcsum < x)return(-1);

        else{
            int target = vcsum - x , sub_array_front = 0 , sub_array_len = -1 , accumulation = 0;
            for(int i=0 ; i<vclen ; i++){
                accumulation += nums[i];
                if(accumulation > target){
                    while(accumulation > target){
                        accumulation -= nums[sub_array_front];
                        sub_array_front++;
                    }
                }
                if(accumulation == target)
                    sub_array_len = max(sub_array_len , (i-sub_array_front)+1);
            }

            if(sub_array_len != -1)
                return(vclen - sub_array_len);
            else
                return(-1);
        }
    }
};
