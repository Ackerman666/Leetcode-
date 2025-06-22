class Solution {
public:

    TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q){
        if((p->val <= node->val) && (q->val >= node->val) )
            return(node);
        else if(p->val > node->val)
            return(LCA(node->right, p, q));
        else
            return(LCA(node->left, p, q));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val > q->val)
            return(LCA(root, q, p));
        return(LCA(root, p, q));
    }
};
