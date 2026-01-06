class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        if(n == 1) return 0;

        vector<int> profit(n, 0);
        for(int i=1; i<=k ; ++i){
            vector<int> pre = profit;
            profit[1] = max(0, prices[1]-prices[0]);
            int best_buy = -prices[0];
            for(int j=2 ; j<n ; ++j){
                best_buy = max(best_buy, pre[j-2]-prices[j-1]);
                profit[j] = max(profit[j-1], best_buy + prices[j]);
            }
        }
        return profit[n-1];
    }
};