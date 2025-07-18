class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1 ; i<=n ;i++){
            if(i%2)              // i is odd
                ans[i]=ans[i/2]+1;
            else
                ans[i]=ans[i/2];
        }
        return(ans);
    }
};
