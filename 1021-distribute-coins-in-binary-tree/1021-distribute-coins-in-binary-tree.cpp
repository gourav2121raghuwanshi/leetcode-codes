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
    int ans=0;
    void solve(TreeNode*root,TreeNode*child){
        if(!child) return ;
        
        solve(child,child->left); solve(child,child->right);

        root->val+=child->val-1;
        ans+=abs(child->val-1);
        child->val=1;
    }
public:
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        solve(root,root->left);
        solve(root,root->right);
        return ans;
    }
};