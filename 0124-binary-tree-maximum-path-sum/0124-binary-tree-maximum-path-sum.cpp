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
    int ans;
    int getSumAtCurrSubTree(TreeNode*root){
        if(!root) return 0;
        int left=getSumAtCurrSubTree(root->left);
        int right=getSumAtCurrSubTree(root->right);
        ans=max({ans,root->val+left,root->val+right,root->val,left+root->val+right});
        return max({root->val+left,root->val+right,root->val});
    }
    // int solve(TreeNode*root){
    //     if(!root) return 0;
    //     // int currSum=-1e9;
    //     int currSum = getSumAtCurrSubTree(root);
    //     ans=max(ans,currSum);
    //     int left=solve(root->left);
    //     int right=solve(root->right);
    //     return max({currSum,left,right,root->val+left+right});
    // }
public:
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        getSumAtCurrSubTree(root);
        return ans;
    }
};