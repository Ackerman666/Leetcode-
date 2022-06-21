class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int InDegree[2001]={0};                      //紀錄節點入度的個數
        int pre_len = prerequisites.size() , sorted_dot_num = 0 , sorted=0;
        vector<vector<int>> child(2001);               //紀錄某點連接到的點的編號
        queue<int> q;

        for(int i=0 ; i<pre_len ; i++){
            int pre = prerequisites[i][0] , next = prerequisites[i][1];
            InDegree[next]++;
            child[pre].push_back(next);
        }

        for(int i=0 ; i<numCourses ; i++){
            if(InDegree[i]==0)
                q.push(i);
        }


        while(!q.empty()){
            int par = q.front() , child_num = child[par].size();
            q.pop();
            sorted++;
            for(int i=0 ; i<child_num ; i++){
                int kid = child[par][i];
                InDegree[kid]--;
                if(InDegree[kid]==0)
                    q.push(kid);
            }
        }

        if(sorted == numCourses)
            return(true);
        else
            return(false);
    }
};
