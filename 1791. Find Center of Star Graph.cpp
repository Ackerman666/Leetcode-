class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int node[100001]={0} , edge_count = edges.size();
        int node_count = edge_count+1;
        int ans;
        for(int i=0 ; i<edge_count ; i++){
            node[edges[i][0]]++;
            node[edges[i][1]]++;
        }

        //find answer
        for(int i=1 ;i<=node_count ;i++){
            //代表該點連到所有邊
            if(node[i]==edge_count){
                ans = i;
                break;
            }
        }
        return(ans);
    }
};
