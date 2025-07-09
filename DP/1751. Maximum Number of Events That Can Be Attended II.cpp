class Solution {
public:

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        // dp[i][j]: the maximum profit we can obtain by selecting at most j events starting from the i-th event
        vector<vector<int>> dp(events.size()+1, vector<int>(k+1, 0));
        vector<int> start;
        for(auto &event : events)
            start.push_back(event[0]);
        
        int n = events.size();
        for(int i=n-1 ; i>=0 ; --i){
            // After choosing this event, find the next event that can be selected without overlapping
            int next = upper_bound(start.begin()+i, start.end(), events[i][1])-start.begin();
            for(int j=1 ; j<=k ; ++j){
                if(next != n)
                    dp[i][j] = max(dp[i+1][j], dp[next][j-1]+events[i][2]);
                else
                    dp[i][j] = max(dp[i+1][j], events[i][2]);
            }
        }

        return dp[0][k];
    }
};
