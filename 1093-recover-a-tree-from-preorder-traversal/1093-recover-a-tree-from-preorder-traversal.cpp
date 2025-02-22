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
public:
    TreeNode* recoverFromPreorder(string s) {
        int n = s.size();

        unordered_map<int, TreeNode*> mp;
        int i = 0;
        int val = 0;
        while (i < n && isdigit(s[i])) {
            val = val * 10 + (s[i] - '0');
            ++i;
        }
        TreeNode* root = new TreeNode(val);
        mp[0] = root;
        while (i < n) {
            int c = 0;
            while (i < n && s[i] == '-') {
                ++c;
                ++i;
            }
            val = 0;
            while (i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                ++i;
            }
            TreeNode* curr = new TreeNode(val);
            TreeNode* par = mp[c - 1];
            if (!par->left) {
                par->left = curr;
            } else
                par->right = curr;
            mp[c] = curr;
        }
        return root;
    }
};