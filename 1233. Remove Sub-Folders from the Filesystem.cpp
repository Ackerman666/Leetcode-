class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        vector<string> ans;
        sort(folder.begin(), folder.end());

        ans.push_back(std::move(folder[0]));
        for(int i=1 ; i<folder.size() ; i++){
            if(folder[i].find(ans.back() + "/") != 0)
                ans.push_back(std::move(folder[i]));
        }
        return ans;
    }
};
