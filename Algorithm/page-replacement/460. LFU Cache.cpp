class LFUCache {
public:

    int Volume;
    int Min_Frequency = 0;
    unordered_map<int, tuple<int, int, list<int>::iterator >> Cache;                  // Cache[Key] = (value, frequency, pointer)
    unordered_map<int, list<int>>   Frequency;

    LFUCache(int capacity) {
        Volume = capacity;
    }

    void update_frequency(int key, int next_frequency){
        //cout<<key<<" "<<next_frequency<<endl;
        list<int>::iterator iter = std::get<2>(Cache[key]);
        Frequency[next_frequency - 1].erase(iter);               //next_frequency - 1 �N��S�Qget or put�e ��key��Frequency
        Frequency[next_frequency].push_front(key);              //��key�b���W�v�U�̪�Q�Ψ�A�ҥH��blist�̫e��
    }

    int get(int key) {
        if(Cache.count(key)){
            int next_frequency = std::get<1>(Cache[key])+1;
            update_frequency(key, next_frequency);
            std::get<1>(Cache[key]) = next_frequency;
            std::get<2>(Cache[key]) = Frequency[next_frequency].begin();
            if(Frequency[Min_Frequency].empty())
                Min_Frequency++;
            return(std::get<0>(Cache[key]));
        }
        return(-1);
    }

    void put(int key, int value) {
        if(Volume == 0)
            return;
        if(Cache.count(key)){
            int next_frequency = std::get<1>(Cache[key])+1 ;
            update_frequency(key, next_frequency);
            std::get<0>(Cache[key]) = value;
            std::get<1>(Cache[key]) = next_frequency;
            std::get<2>(Cache[key]) = Frequency[next_frequency].begin();
            if(Frequency[Min_Frequency].empty())
                Min_Frequency++;
        }
        else{
            if(Cache.size() == Volume){                               //�ثe�֨��w�� �n����LFU�R��
                int remove_key = Frequency[Min_Frequency].back();
                Cache.erase(remove_key);
                Frequency[Min_Frequency].pop_back();
            }
            //���J
            Frequency[1].push_front(key);
            Cache[key] = make_tuple(value, 1, Frequency[1].begin());
            Min_Frequency = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
