class Solution {
public:
    int uniquePaths(int m, int n) {
        //ans[i][j]=k 代表走到(i,j)共有k種方法
        int ans[101][101]={0};

        for(int i=0 ;i<m ; i++){
            for(int j=0 ;j<n ; j++){
                if(i==0 || j==0)
                    ans[i][j]=1;
                else{
                    ans[i][j]=ans[i-1][j] + ans[i][j-1];
                }
            }
        }

        return(ans[m-1][n-1]);

    }
};
