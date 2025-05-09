/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode * left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right || (left->val!=right->val))
            return false;
        
        return solve(left->right,right->left) && solve(left->left,right->right);

    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return true;
        if (!root->left || !root->right ||
            (root->left->val != root->right->val))
            return false;

        return solve(root->left, root->right);
    }
};