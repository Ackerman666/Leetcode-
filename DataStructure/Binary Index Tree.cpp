#define LOWBIT(x) (x & -x)

class BIT{
    private:
        vector<int> nodes;
        int size;
        int prefix(int idx){
            int sum = 0;
            while(idx <= size && idx>0){
                sum += nodes[idx];
                idx = idx-LOWBIT(idx);
            }
           return sum;
        }
    public:
        BIT(int n){
            size = n;
            nodes.resize(n+1, 0);
        }
        int query(int start, int end){
            return prefix(end) - prefix(start-1);
        }

        void update(int idx, int val){
            while(idx <= size && idx>0){
                nodes[idx] += val;
                idx = idx+LOWBIT(idx);
            }
        }
};