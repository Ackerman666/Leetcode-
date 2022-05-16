class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int ans = INT_MIN , vclen = nums.size() , acc=0;
       for(int i=0 ;i<vclen ;i++){
           acc+=nums[i];
           ans=max(ans , acc);
           if(acc<0)
               acc=0;
       }
       return(ans);
    }
};
