/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        if (!root)
            return {};

        unordered_map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front->left) {
                par[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                par[front->right] = front;
                q.push(front->right);
            }
        }

        q.push(target);
        vector<int> ans;
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        while (k-- && !q.empty()) {
            int s = q.size();
            while (s--) {
                auto front = q.front();
                q.pop();
                if (front->left && !vis.count(front->left)) {
                    q.push(front->left);
                    vis.insert(front->left);
                    if (k == 0)
                        ans.push_back(front->left->val);
                }
                if (front->right && !vis.count(front->right)) {
                    q.push(front->right);
                    vis.insert(front->right);
                    if (k == 0)
                        ans.push_back(front->right->val);
                }
                if (par[front] && !vis.count(par[front])) {
                    q.push(par[front]);
                    vis.insert(par[front]);
                    if (k == 0)
                        ans.push_back(par[front]->val);
                }
            }
        }
        return ans;
    }
};