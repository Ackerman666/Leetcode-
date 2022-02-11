class Solution {
public:
    void dfs(int loc , int sum , vector<vector<int>>& ans , vector<int>& temp , int target , vector<int>& candidates ,int candidates_len){
    if(sum==target){
        ans.push_back(temp);
        return;
    }
    for(int i=loc ; i<candidates_len ; i++){
        int num=candidates[i] , total=sum+num;
        if( total > target)
            break;
        temp.push_back(num);
        dfs(i,total,ans,temp,target,candidates,candidates_len);
        temp.pop_back();
    }
}



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int candidates_len=candidates.size();
        dfs(0,0,ans,temp,target,candidates,candidates_len);
        return ans;
    }
};
