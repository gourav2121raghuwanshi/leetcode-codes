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
    int minSwaps(vector<int>& nums) {
        int ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < nums.size(); i++) {
            int index = v[i].second;
            if (index != i) {
                swap(v[index], v[i]);
                ++ans;
                --i;
            }
        }
        return ans;
    }

public:
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            while (size--) {
                auto front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            int c = minSwaps(v);
            ans += c;
        }
        return ans;
    }
};