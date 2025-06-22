class Solution {
public:

    void Level_Order(map<int, vector<int>> &Level, TreeNode* parent, int num){
        TreeNode *left = parent->left, *right = parent->right;
        if(left!=nullptr){
            Level[num].push_back(left->val);
            Level_Order(Level, left, num+1);
        }
        if(right!=nullptr){
            Level[num].push_back(right->val);
            Level_Order(Level, right, num+1);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<int>> level;
        map<int, vector<int>>::iterator iter;
        if(root!=nullptr){
            level[1].push_back(root->val);
            Level_Order(level, root, 2);
        }
        for(iter=level.begin() ; iter!=level.end() ; iter++)
            ans.push_back(iter->second);
        return(ans);
    }
};
