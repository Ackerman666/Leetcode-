class Sgtree{

    private:
        vector<int> nodes;
        int l, r;
        void update(int idx, int val, int l, int r, int node){
            // nodes[node] range : [l..idx..r] , the value of idx update -> nodes[node] value update
            nodes[node]+=val;
            if(l == r)
                return;
            int mid = (l+r) >> 1;
            if(idx<=mid)
                update(idx, val, l, mid, node<<1);
            else
                update(idx, val, mid+1, r, (node<<1)+1);
        }
        int query(int start, int end, int l, int r, int node){
            if(start<=l && end>=r)
                return nodes[node];
            int mid = (l+r)>>1, result = 0;
            if(start <= mid)
                result+=query(start, end, l, mid, node<<1);
            if(end > mid)
                result+=query(start, end, mid+1, r, (node<<1)+1);
            return result;
        }
    public:
        Sgtree(int n){
            nodes.resize(4*n, 0);
            l = 0;
            r = n-1;
        }
        int query(int start, int end){
            if(start > end || start > r || end < l)
                return -1;
            return query(start, end, l, r, 1);
        }

        void update(int idx, int val){
            if(idx<l || idx>r)
                return;
            update(idx, val, l, r, 1);
        }
};