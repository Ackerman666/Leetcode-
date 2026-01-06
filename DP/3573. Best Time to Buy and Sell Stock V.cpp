class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if(n == 1) return 0;

        vector<vector<long long>> profit(n, vector<long long>(k+1,0));
        for(int i=1; i<=k ; ++i){
            profit[1][i] = max<long long>(0, prices[1]-prices[0]);
            profit[1][i] = max<long long>(profit[1][i], prices[0]-prices[1]);
            long long best_buy = -prices[0], best_short = prices[0];
            for(int j=2 ; j<n ; ++j){
                best_buy = max<long long>(best_buy, profit[j-2][i-1]-prices[j-1]);   
                best_short = max<long long>(best_short, profit[j-2][i-1]+prices[j-1]);
                // Keep track of the highest profit we can get from either transaction type on this day
                long long today_best_operate = max(best_buy + prices[j], best_short - prices[j]);
                profit[j][i] = max<long long>(profit[j-1][i], today_best_operate); 
            }
        }
        return profit[n-1][k];
    }
};