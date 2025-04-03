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
    int getSumAtCurrSubTree(TreeNode*root,int &currSum){
        if(!root) return 0;
        int left=getSumAtCurrSubTree(root->left,currSum);
        int right=getSumAtCurrSubTree(root->right,currSum);
        currSum=max({root->val,currSum,root->val+left,root->val+right,root->val+right+left});
        return max({root->val+left,root->val+right,root->val});
    }
    void solve(TreeNode*root){
        if(!root) return ;
        int currSum=-1e9;
        getSumAtCurrSubTree(root,currSum);
        ans=max(ans,currSum);
        solve(root->left);
        solve(root->right);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};