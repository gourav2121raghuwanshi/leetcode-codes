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
    void solve(TreeNode*root,int &s){
        if(!root) return ;
         solve(root->right,s);
        int val=root->val;
        root->val+=s;
        s+=val;
       solve(root->left,s);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int s=0;
        solve(root,s);
        return root;

    }
};