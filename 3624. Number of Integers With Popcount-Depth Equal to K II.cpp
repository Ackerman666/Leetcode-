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

class Solution {
public:

    int set_bits(long long num){
        int count = 0;
        while(num){
            num &= (num-1);
            ++count;
        }
        return count;
    }

    int get_depth(long long num){
        if(num == 0 || num == 1)
            return 0;
        return get_depth(set_bits(num))+1;
    }
    
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        vector<int> depth(nums.size(), 0);
        for(int i=0 ; i<nums.size() ; ++i){
            depth[i]=(get_depth(nums[i]));
        }

        int l = 0, r = depth.size();

        vector<BIT> trees(6, BIT(nums.size()));
        for(int i=0 ; i<6 ; ++i){
            for(int j=0 ; j<depth.size() ; ++j){
                if(depth[j] == i)
                    trees[i].update(j+1, 1);
            }
        }

        vector<int> ans;
        for(auto &q : queries){
            if(q[0] == 1){
                int k = q[3];
                ans.push_back(trees[k].query(q[1]+1, q[2]+1));
            }
            else{
                int ori_depth = depth[q[1]];
                if(ori_depth <= 5)
                    trees[ori_depth].update(q[1]+1, -1);
                depth[q[1]] = get_depth(q[2]);
                if(depth[q[1]] <= 5)
                    trees[depth[q[1]]].update(q[1]+1, 1);
            }
        }
        return ans;
    }
};