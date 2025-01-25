class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegreen(numCourses), order;
        vector<vector<int>> graph(numCourses);

        for(auto &edge : prerequisites){
            graph[edge[1]].push_back(edge[0]);
            ++indegreen[edge[0]];
        }

        // Kahn’s algorithm
        while(1){
            bool find = false;
            for(int i=0 ; i<numCourses ; i++){
                if(indegreen[i] == 0){
                    indegreen[i] = -1;
                    for(auto &to : graph[i]){
                        --indegreen[to];
                    }
                    order.push_back(i);
                    find = true;
                }
            }
            if(!find)
                break;
        }
        if(order.size() != numCourses)
            order.clear();

        return order;

    }
};
