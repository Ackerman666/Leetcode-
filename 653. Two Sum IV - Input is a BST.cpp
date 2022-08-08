class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        int q_len;
        unordered_map<int, bool> mp;
        queue<TreeNode*> q;
        q.push(root);
        q_len = q.size();
        while(q_len){
            TreeNode* node = q.front();
            if(mp.count(k-node->val))
                return(true);
            mp[node->val]=true;
            q.pop();
            if(node->left!=nullptr)
                q.push(node->left);
            if(node->right!=nullptr)
                q.push(node->right);
            q_len--;
            if(q_len==0)
                q_len = q.size();
        }
        return(false);
    }
};
