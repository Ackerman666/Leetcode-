class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;

        vector<vector<int>> profit(n, vector(3,0));
        profit[1][2] = profit[1][1] = max(0, prices[1]-prices[0]);
        for(int i=1; i<=2 ; ++i){
            // For the i-th transaction, when deciding to sell on day j,
            // best_buy stores the maximum value achievable from a previous buy
            int best_buy = -prices[0];
            for(int j=2 ; j<n ; ++j){
                best_buy = max(best_buy, profit[j-2][i-1]-prices[j-1]);
                profit[j][i] = max(profit[j-1][i], best_buy + prices[j]);
            }
        }
        return profit[n-1][2];
        

    }
};