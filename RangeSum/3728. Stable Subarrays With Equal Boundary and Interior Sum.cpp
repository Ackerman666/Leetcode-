class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        unordered_map<int, unordered_map<long long, int>> mp;


        long long ans = 0, prefix = 0;
        for(int i=0 ; i<n ; ++i){
            int c = capacity[i];
            prefix += c;
            long long target = prefix - (c<<1);
            ans += mp[c][target];
            if(c==0 && i>0 && capacity[i-1]==0){
                --ans;
            }
            ++mp[c][prefix];
        }

        return ans;
    }
};