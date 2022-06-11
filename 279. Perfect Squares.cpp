class Solution {
public:
    int numSquares(int n) {
       int DP[10001]={0};        //DP[i]=k �N��i�i�ѳ̤�k�ӥ���βզ�
       for(int i=1 ; i<=n ;i++)
           DP[i]=i;
       for(int len=2 ; len*len<=n ; len++){
           int square = len * len;
           for(int i=square ; i<=n ;i++){
               DP[i]=min(DP[i],DP[i-square]+1);
           }
       }
       return(DP[n]);
    }
};
