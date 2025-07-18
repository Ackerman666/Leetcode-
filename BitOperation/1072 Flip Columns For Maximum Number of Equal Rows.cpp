class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        unordered_map<bitset<300>, int> pattern; // Store the frequency of each pattern
        
        int ans = 0, m = matrix.size(), n = matrix[0].size();

        // Generate the pattern for the row
        for(int i=0 ; i<m ; ++i){
            bitset<300> bits;
            for(int j=1 ; j<n ; ++j){
                if(matrix[i][j] == matrix[i][0])
                    bits[j] = 0;
                else
                    bits[j] = 1;
            }
            ++pattern[bits];
        }

        for(auto& [key, value] :pattern){
            ans = max(ans, value);
        }
        return ans;
    }
};
