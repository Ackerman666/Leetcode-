class Solution {
public:

    int ans = 0;

    long long dfs(int node, unordered_map<int, list<int>> &conn, vector<int>& cost){
        long long c = cost[node], max_sub_path = 0, path;
        int max_sub_path_counts = 0;
        // Find the maximum accumulated path cost among child nodes,
        // and count how many children have this maximum path
        for(auto &child : conn[node]){
            if(conn[child].size())
                path = dfs(child, conn, cost);
            else
                path = cost[child];
            if(max_sub_path < path){
                max_sub_path = path;
                max_sub_path_counts = 1;
            }
            else if(max_sub_path == path)
                ++max_sub_path_counts;
        }
        // The number of children not on the maximum path = total children - number of max path children
        // These non-maximum children need to be increased (by cost) to match the longest path
        ans += conn[node].size()-max_sub_path_counts;
        return cost[node] + max_sub_path;
    }
   
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        unordered_map<int, list<int>> conn;
        // build linked list
        for(auto &edge : edges)
            conn[edge[0]].push_back(edge[1]);

        dfs(0, conn, cost);
        return ans;
    }
};