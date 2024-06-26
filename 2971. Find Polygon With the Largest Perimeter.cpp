class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        long long len = nums.size(), ans = 0, prefix_sum = nums[0] + nums[1];
        
        for(int i=2 ; i<len ; i++){
            if(nums[i] < prefix_sum ){
                ans = prefix_sum + nums[i];
            }
            prefix_sum += nums[i];
        }
        return (ans == 0) ? -1 : ans;

    }
};
