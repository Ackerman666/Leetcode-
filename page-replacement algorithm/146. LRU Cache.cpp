class LRUCache {
public:

    unordered_map<int, pair<int, list<int>::iterator>> Cache;         //Cache[key] = [value, iter]
    list<int> LRU_list;                                              //纗key砆弄丁翴抖, 程Τ砆put or get碞list程玡
    int Volume;

    LRUCache(int capacity) {
        Volume = capacity;
    }

    int get(int key) {
        if(Cache.count(key)){
            LRU_list.erase(Cache[key].second);
            LRU_list.push_front(key);
            Cache[key].second = LRU_list.begin();
            return(Cache[key].first);
        }
        else
            return(-1);
    }

    void put(int key, int value) {
        if(Volume == 0)
            return;
        if(Cache.count(key)){
            LRU_list.erase(Cache[key].second);
        }
        else if(Cache.size() == Volume){
            Cache.erase(LRU_list.back());       //list程程ぃ盽ノ
            LRU_list.pop_back();
        }
        LRU_list.push_front(key);
        Cache[key].first = value;
        Cache[key].second = LRU_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
