#define LOW_BIT(x) (x & -x) 

class BIT{
    private:
        vector<int> nodes;
        int size;
        int prefix(int idx){
            int sum = 0;
            while(idx>0 && idx<=size){
                sum += nodes[idx];
                idx -= LOW_BIT(idx);
            }
            return sum;
        }

    public:
        BIT(int n){
            nodes.resize(n+1, 0);
            size = n;
        }
        void update(int idx, int val){
            while(idx>0 && idx<=size){
                nodes[idx] += val;
                idx += LOW_BIT(idx);
            }
        }
        int query(int idx){
            if(idx<=0 || idx>size)
                return 0;
            return prefix(idx);
        }
};





class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size(), ans = 0, max_rating = *max_element(rating.begin(), rating.end());
        BIT l_BIT(max_rating), r_BIT(max_rating);
        for(int i=1 ; i<len ; ++i)
            r_BIT.update(rating[i], 1);

        l_BIT.update(rating[0], 1);
        
        for(int i=1 ; i<len-1 ; ++i){
            int l_bigger = l_BIT.query(max_rating) - l_BIT.query(rating[i]);
            int r_bigger = r_BIT.query(max_rating) - r_BIT.query(rating[i]);
            int l_smaller = l_BIT.query(rating[i]-1);
            int r_smaller = r_BIT.query(rating[i]-1);
            ans += l_bigger*r_smaller + l_smaller*r_bigger;
            l_BIT.update(rating[i], 1);
            r_BIT.update(rating[i], -1);
        }
        return ans;
    }
};