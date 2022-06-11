class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1 , zero_count=0 ,nums_size = nums.size();
        for(int i=0 ; i<nums_size ; i++){
            if(nums[i]==0)
                zero_count++;
            else
                product*=nums[i];
        }
        vector<int> ans(nums_size,0);
        if(zero_count>=2)
            return(ans);
        else{
            if(zero_count==1){
                for(int i=0 ; i<nums_size ; i++){
                    if(nums[i]==0){
                        ans[i]=product;
                        break;
                    }
                }
            }
            else{
                for(int i=0 ; i<nums_size ; i++)
                    ans[i] = product / nums[i];
            }
            return(ans);
        }
    }
};
