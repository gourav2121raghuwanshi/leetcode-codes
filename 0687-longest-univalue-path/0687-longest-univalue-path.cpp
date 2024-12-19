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
    int solve(TreeNode*root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int lans=0;
        int rans=0;
        if(root->left && root->val == root->left->val){
            lans=1+l;
        }
        if(root->right && root->val == root->right->val){
            rans=1+r;
        }
        ans=max(ans,lans+rans);
        return max(lans,rans);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        // ans=1;
        solve(root);
        return ans;
    }
};