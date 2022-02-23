/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* cur , stack<int> &st , int &nodenum){
        if(cur!=nullptr){
            nodenum++;
            int curvalue=cur->val;
            inorder(cur->left,st,nodenum);
            if( (!st.empty() && curvalue > st.top()) || st.empty())
                st.push(curvalue);
            inorder(cur->right,st,nodenum);
        }
    }

    bool isValidBST(TreeNode* root) {
        int nodenum=0;
        stack<int> st;
        inorder(root,st,nodenum);
        return (nodenum==st.size());
    }
};
