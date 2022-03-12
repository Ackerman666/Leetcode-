class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101]={0};                    //搶1~i間房子能得到最多金額的數目
        int house_len = nums.size();
        dp[1]=nums[0];
        for(int i=2 ; i<=house_len ;i++){
            dp[i]=max(dp[i-1] , dp[i-2]+nums[i-1]);
        }
        return(dp[house_len]);
    }
};
