class Solution {
public:
    //Boyer–Moore majority vote algorithm(摩爾投票算法)
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], count=1, len = nums.size();
        for(int i=1 ; i<len ; i++){
            if(nums[i]==ans) count++;
            else{
                if(count==1){
                    ans=nums[i];
                }
                else
                    count--;
            }
        }
        return(ans);
    }
};
