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
    TreeNode* succ(TreeNode* root) {
        TreeNode* succ = root->right;
        while (succ->left)
            succ = succ->left;
        return succ;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (root->left && !root->right) {
                TreeNode* t = root->left;
                delete root;
                return t;
            } else if (root->right && !root->left) {
                TreeNode* t = root->right;
                delete root;
                return t;
            } else {
                TreeNode* su = succ(root);
                root->val = su->val;
                root->right = deleteNode(root->right, su->val);
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};