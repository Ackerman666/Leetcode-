class Solution {
public:

    //利用call by reference 可以減去呼叫cmp時參數複製的時間
    static bool cmp(vector<int> &a, vector<int> &b){
        return(a[1] > b[1]);
    }

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int roomlen = rooms.size(), qlen = queries.size(), index = 0;
        vector<int> ans(qlen, -1);
        //儲存滿足當前需求的房間編號
        set<int> s;

        for(int i=0 ; i<qlen ; i++) queries[i].push_back(i);

        //根據size由大至小排序
        sort(rooms.begin(), rooms.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);


        for(int i=0 ; i<qlen ; i++){
            int request_size = queries[i][1], roomid = queries[i][0], roomindex = queries[i][2];
            while(index < roomlen){
                //如果當前房間size滿足需求，就加進set
                if(rooms[index][1] >= request_size){
                    s.insert(rooms[index][0]);
                    index++;
                }
                else{
                    break;
                }
            }
            if(s.size()){
                //在所有滿足的房間編號中，利用lower_bound找到離目標最近的房間編號
                auto iter = s.lower_bound(roomid);
                if(iter == s.begin()) ans[roomindex] = *iter;
                else if(iter == s.end()) ans[roomindex] = *(--iter);
                else if(*iter-roomid < roomid - *(--iter))
                    ans[roomindex] = (*(++iter));
                else
                    ans[roomindex] = (*iter);
            }
        }

        return(ans);

    }
};
