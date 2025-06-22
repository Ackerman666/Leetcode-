class Solution {
public:

    bool dfs(TreeNode *nodeA, TreeNode *nodeB){
        if(nodeA==nullptr && nodeB==nullptr)
            return(true);
        else if(nodeA==nullptr || nodeB==nullptr) //¤£¹ïºÙ
            return(false);
        if(nodeA->val != nodeB->val)
            return(false);
        return(dfs(nodeA->left, nodeB->right) && dfs(nodeA->right, nodeB->left));
    }

    bool isSymmetric(TreeNode* root) {
        return(dfs(root->left, root->right));
    }
};
