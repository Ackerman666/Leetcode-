class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        bitset<2001> b;
        int diff = 0, ans = 0, left = 0, len = nums.size();

        for(auto &num : nums)
            b.set(num);

        diff = b.count();

        for(int i=0 ; i<len ; ++i){
            ++mp[nums[i]];
            while(mp.size() == diff){
                ans += (len - i);
                if(--mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                ++left;
            }
        }

        return ans;

    }
};
