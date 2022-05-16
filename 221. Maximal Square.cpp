class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0 , DP[301][301]={0} , m = matrix.size()-1 , n = matrix[0].size()-1;

        for(int i=m ;i>=0 ;i--){
            for(int j=n ;j>=0 ;j--){
                char cur_char = matrix[i][j];
                if(i==m || j==n)
                    DP[i][j]=cur_char-'0';
                else if(cur_char=='1'){
                    int proper_len = min(DP[i+1][j] , min(DP[i][j+1] , DP[i+1][j+1]));
                    DP[i][j]=proper_len+1;
                }
                ans=max(ans,DP[i][j]);
            }
        }
        return(ans*ans);
    }
};
