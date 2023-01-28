class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;

        //-------------------------------�Q��Bellman-Ford�t��k
        for(int i=0 ; i<=k ; i++){       //E.G. ��2���j�� -> ��src��U�I�̵u���|�̦h�|�g�L2����, ��n���j�� -> ��src��U�I�̵u���|�̦h�g�Ln����
            vector<int> temp = dis;     //��temp�������edis��T
            for(int i=0 ; i<flights.size() ; i++){
                int mid = flights[i][0], des = flights[i][1], cost = flights[i][2];
                if(dis[mid] != INT_MAX)
                    temp[des] = min(temp[des], dis[mid] + cost);
            }
            dis = temp;
        }
        if(dis[dst] == INT_MAX)
            return(-1);
        return(dis[dst]);
    }
};
