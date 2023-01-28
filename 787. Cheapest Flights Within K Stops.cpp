class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;

        //-------------------------------利用Bellman-Ford演算法
        for(int i=0 ; i<=k ; i++){       //E.G. 第2次迴圈 -> 表src到各點最短路徑最多會經過2條邊, 第n次迴圈 -> 表src到各點最短路徑最多經過n條邊
            vector<int> temp = dis;     //用temp紀錄先前dis資訊
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
