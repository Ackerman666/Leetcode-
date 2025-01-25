class Solution {
public:

    bool cycle_detect(int node, vector<int> &cycle, vector<bool> &visit, vector<vector<int>>& graph) {
        bool detect = false;
        vector<int> &edge = graph[node];
        visit[node] = 1;

        for (int i = 0; i < edge.size(); i++) {
            // Skip neighbors confirmed to have no cycle
            if (cycle[edge[i]] == 0)
                continue;
            // Cycle detected via neighbor; terminate loop and mark this node
            if (visit[edge[i]] || cycle[edge[i]] == 1 || cycle_detect(edge[i], cycle, visit, graph)) {
                detect = true;
                break;
            }
        }

        visit[node] = 0;
        cycle[node] = detect;
        return detect;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> cycle(graph.size(), 0);
        vector<bool> visit(graph.size(), 0);
        vector<int> ans;

        fill(cycle.begin(), cycle.end(), -1);

        for (int i = 0; i < graph.size(); i++) {
            // Perform DFS only if the cycle status is unknown
            if (cycle[i] == -1)
                cycle_detect(i, cycle, visit, graph);
            // If no cycle, add to result
            if (!cycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};
