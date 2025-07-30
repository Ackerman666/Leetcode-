class Solution {
public:
    int minJumps(vector<int>& nums) {
        int max_e = *max_element(nums.begin(), nums.end());
        vector<int> spf(max_e+1, 0);
        for(int i=2 ; i<=max_e ; ++i){
            if(!spf[i]){
                for(int j=i ; j<=max_e ; j+=i){
                    if(!spf[j])
                        spf[j] = i;
                }
            }
        }
        
        // Map each prime factor p to all indices i where p divides nums[i]
        unordered_map<int, vector<int>> teleportation;
        for(int i=0 ; i<nums.size() ; ++i){
            int tmp = nums[i];
            while(tmp > 1){
                int p = spf[tmp];
                teleportation[p].push_back(i);
                while(tmp % p == 0) tmp /= p;
            }
        }

        int step = 0, target = nums.size()-1;
        queue<int> q;
        q.push(0);
        vector<int> dis(target+1, -1);
        dis[0] = 0;
        
        while(q.size()){
            int node = q.front(), d = dis[node] + 1;
            q.pop();
            if(node-1>=0 && dis[node-1]==-1){
                q.push(node-1);
                dis[node-1] = d;
            }
            if(node+1<=target && dis[node+1]==-1){
                q.push(node+1);
                dis[node+1] = d;
            }
            if(spf[nums[node]] == nums[node] && teleportation.count(nums[node])){
                for(auto &idx : teleportation[nums[node]]){
                    if(dis[idx]==-1){
                        q.push(idx);
                        dis[idx] = d;
                    }
                }
                teleportation.erase(nums[node]);
            }
            if(dis[target] != -1) return dis[target];
        }
        return -1;
    }
};
