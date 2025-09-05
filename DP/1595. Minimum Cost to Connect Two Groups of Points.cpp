class Solution {
public:

    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size(), bound = (1<<m)-1;
        vector<vector<long long>> dp(n+1, vector<long long>(bound+1, INT_MAX));
        vector<int> min_cost(m, INT_MAX);

        // Record the minimum cost to connect each point in the second group to the first group 
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j)
                min_cost[i] = min(min_cost[i], cost[j][i]);
        }
        
        dp[0][0] = 0;

        // dp[i][j]: minimum cost after connecting the first i points in group 1 with mask = j
        // Here, mask is a bitmask representing which nodes in group 2 are already connected.
        // For example, mask = 6 (binary 110) means nodes 2 and 3 in group 2 are connected.
        for(int i=0 ; i<n ; ++i){
            for(int mask = 0; mask <= bound; ++mask){
                  for(int conn = 0; conn < m ; ++conn){
                    int new_mask = mask | (1<<(conn));
                    dp[i+1][new_mask] = min(dp[i+1][new_mask], dp[i][mask]+cost[i][conn]);
                }
            }
        }
 
        // For each dp[n][mask], find the "unconnected" points in group 2,
        // and use min_cost to connect them to group 1 at minimal cost
        for(int mask = 1; mask <= bound; ++mask){
            int extra = 0;
            for(int i=1 ; i<=m ; ++i){
                if(!(mask & (1<<(i-1))))
                    extra += min_cost[i-1];
            }
            dp[n][bound] = min(dp[n][bound], dp[n][mask]+extra);
        }

        return dp[n][bound];
    }
};