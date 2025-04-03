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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, map<int, multiset<int>>> mp; // col,row,values
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int row = front.second.first;
            int col = front.second.second;
            TreeNode* node = front.first;
            mp[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }
        for (auto& i : mp) {
            vector<int> v;
            // same col
            for (auto& j : i.second) {
                // elements of same row
                for (auto& k : j.second) {
                    v.push_back(k);
                }
            }

            ans.push_back(v);
        }
        return ans;
    }
};