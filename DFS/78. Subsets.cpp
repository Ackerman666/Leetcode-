class Solution {
public:

    void dfs(vector<int>& nums , vector<vector<int>>& ans , vector<int> candidate , int index){
        ans.push_back(candidate);
        for(int i=index ; i<nums.size() ; i++){
            vector<int> temp = candidate;
            temp.push_back(nums[i]);
            dfs(nums , ans , temp , i+1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> vc;
        dfs(nums , ans ,  vc , 0);
        return(ans);
    }
};
