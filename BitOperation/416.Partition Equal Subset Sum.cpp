class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> appear(0b1);
        int target = accumulate(nums.begin(), nums.end(), 0);
        for(auto &num : nums)
            // e.g., appear = 0b0011 → sums 0 and 1 are reachable
            // now if we have num : 2, appear << 2 = 0b1100 → now 2 and 3 become reachable
            // OR to combine all reachable sums
            appear |= (appear << num);
        return !(target&1) && appear[target >> 1];
    }
};
