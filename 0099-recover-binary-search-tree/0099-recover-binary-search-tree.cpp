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
    TreeNode* prev;
    TreeNode* one;
    TreeNode* two;

    void in(TreeNode* root) {
        if (!root)
            return;
        in(root->left);
        if (prev) {
            if (root->val <= prev->val) {
                if (one == nullptr) {
                    one = root;
                    two = prev;
                } else {
                    one=root;
                }
            }
        }
        prev = root;
        in(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        prev = one = two = nullptr;

        in(root);
        int t = one->val;
        one->val = two->val;
        two->val = t;
    }
};