class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {   //½ò¶¥±è°ÝÃD
        int mod = 1e9+7, ans = 0;
        int DP[100002]={0};
        DP[0] = 1;
        for(int i=1 ; i<=high ; i++){
            int lenA = i - zero, lenB = i - one;
            if(lenA >= 0 ) DP[i] = (DP[i] + DP[lenA]) % mod;
            if(lenB >= 0 ) DP[i] = (DP[i] + DP[lenB]) % mod;
            if(i>=low) ans = (ans + DP[i]) % mod;
        }
        return(ans);
    }
};
