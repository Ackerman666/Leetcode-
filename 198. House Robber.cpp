class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101]={0};                    //�m1~i���Фl��o��̦h���B���ƥ�
        int house_len = nums.size();
        dp[1]=nums[0];
        for(int i=2 ; i<=house_len ;i++){
            dp[i]=max(dp[i-1] , dp[i-2]+nums[i-1]);
        }
        return(dp[house_len]);
    }
};
