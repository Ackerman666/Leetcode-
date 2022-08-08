class Solution {
public:

    void Insert(TreeNode* cur, TreeNode* target){
        if(target->val > cur->val){
            if(cur->right==nullptr)
                cur->right = target;
            else
                Insert(cur->right, target);
        }
        else{
            if(cur->left==nullptr)
                cur->left = target;
            else
                Insert(cur->left, target);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* target = new TreeNode(val);
        if(root==nullptr)
            return(target);
        Insert(root, target);
        return(root);
    }
};
