class Solution {
public:
    void DP_INI(int DP[]){
        for(int i=1;i<10001;i++)
            DP[i]=99999999;
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return(0);
        int DP[10001]={0} , cointype=coins.size();
        DP_INI(DP);
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++){
            for(int j=0;j<cointype;j++){
                int value=coins[j];
                if(value>i)
                    break;
                else
                    DP[i]=min(DP[i],1+DP[i-value]);
            }
        }
        if(DP[amount]==99999999)
            return(-1);
        return(DP[amount]);
    }
};
