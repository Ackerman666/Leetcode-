class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> comb(k,0);

        for(int i=1 ; i<=k ; i++)
            comb[i-1] = i;
        ans.push_back(comb);

        int index = k-1;
        // Exhaustive  (e.g. n=4, k=3  [123] -> [124] -> [134] ...)
        while(index >= 0){
            ++comb[index];
            if(comb[index] > n){
                --index;
                continue;
            }
            if(index != (k-1)){
                comb[index+1] = comb[index];
                ++index;
                continue;
            }
            ans.push_back(comb);
        }
     
        return ans; 
    }
};
