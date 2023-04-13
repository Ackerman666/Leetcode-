class Solution {
public:

    //�Q��call by reference �i�H��h�I�scmp�ɰѼƽƻs���ɶ�
    static bool cmp(vector<int> &a, vector<int> &b){
        return(a[1] > b[1]);
    }

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int roomlen = rooms.size(), qlen = queries.size(), index = 0;
        vector<int> ans(qlen, -1);
        //�x�s������e�ݨD���ж��s��
        set<int> s;

        for(int i=0 ; i<qlen ; i++) queries[i].push_back(i);

        //�ھ�size�Ѥj�ܤp�Ƨ�
        sort(rooms.begin(), rooms.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);


        for(int i=0 ; i<qlen ; i++){
            int request_size = queries[i][1], roomid = queries[i][0], roomindex = queries[i][2];
            while(index < roomlen){
                //�p�G��e�ж�size�����ݨD�A�N�[�iset
                if(rooms[index][1] >= request_size){
                    s.insert(rooms[index][0]);
                    index++;
                }
                else{
                    break;
                }
            }
            if(s.size()){
                //�b�Ҧ��������ж��s�����A�Q��lower_bound������ؼг̪񪺩ж��s��
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
