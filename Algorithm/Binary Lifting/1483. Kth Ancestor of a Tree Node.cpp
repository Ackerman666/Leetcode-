class TreeAncestor {
public:
    vector<vector<int>> anc;
    TreeAncestor(int n, vector<int>& parent) {
        int h = log2(n)+1;

        anc.resize(n, vector<int>(h+1));
        for(int i=0 ; i<n ; ++i){
            anc[i][0] = parent[i];
        }
        for(int i=1 ; i<=h ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(anc[j][i-1]!=-1)
                    anc[j][i] = anc[anc[j][i-1]][i-1];
                else
                    anc[j][i] = -1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int base = 0;
        while(k){
            if(k&1)
                node = anc[node][base];
            if(node == -1)
                return -1;
            ++base;
            k >>= 1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */