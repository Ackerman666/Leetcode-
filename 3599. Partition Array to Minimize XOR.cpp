class Solution {
public:
    // TODO : not use recursive. 
    int find(vector<vector<int>> &dp, vector<int>& nums, int idx, int k, int len){
        
        // nums[idx..end] to form 1 subarray, only one possible xor value
        if(k == 1){
            dp[idx][k] = 0;
            for(int i=idx ; i<=len ; ++i)
                dp[idx][k] ^= nums[i];
            return dp[idx][k];
        }
       
        if(dp[idx][k] == -1){
            int c_xor = 0, min_xor = INT_MAX;
            // simulate partiction condiction
            for(int i=idx ; i<len-k+2 ; ++i){
                c_xor ^= nums[i];
                min_xor = min(min_xor, max(c_xor, find(dp, nums, i+1, k-1, len)));
            }
            dp[idx][k] = min_xor;
        }
        return dp[idx][k];
    }


    int minXor(vector<int>& nums, int k) {
        int len = nums.size()-1;
        if(len == 0)
            return nums[0];
        // dp[i][k]: the minimum possible value of the maximum XOR among k subarrays
        // when partitioning the nums[i..end] into k subarrays.
        vector<vector<int>> dp(nums.size(), vector<int>(k+1,-1));
        return find(dp, nums, 0, k, len);
    }
};
