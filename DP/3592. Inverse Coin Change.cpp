class Solution {
public:

    void update_comb(int coins, int comb[]){
        for(int i=1 ; i<101 ; ++i){
            if(i >= coins)
                comb[i] += comb[i-coins];
        }
    }

    
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coins, empty;
        int comb[101] = {0};
        comb[0] = 1;

        for(int i=1 ; i<=numWays.size() ; ++i){
            if(numWays[i-1]!=0){
                // the current number of combinations is less than the required combinations -> add coin
                if(numWays[i-1] > comb[i]){
                    coins.push_back(i);
                    update_comb(i, comb);
                    // After adding the new coin, the number of combinations is still "not match" requirement ways
                    if(numWays[i-1] != comb[i])
                        return empty;
                }
            }
            else{
                // requirement ways = 0, but the number of combinations > 0 
                if(comb[i] > 0)
                    return empty;
            }
        }
        return coins;  
    }
};
