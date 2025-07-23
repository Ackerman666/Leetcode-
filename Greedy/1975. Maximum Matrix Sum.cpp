class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int neg_count = 0, ans = 0;
        int n_min = INT_MAX;
        bool has_zero = false;

        for(auto &m : matrix){
            for(auto &n : m){
                if(n < 0){
                    ++neg_count;
                    n = -n;
                }
                if(n == 0)
                    has_zero = true;
                ans += n;
                n_min = min(n_min, n);
            }
        }
        if(!has_zero && neg_count % 2 != 0)
            ans -= 2*n_min;
        return ans;

    }
};
