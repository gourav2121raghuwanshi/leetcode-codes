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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;
        
        bool level = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            if (level) {
                queue<TreeNode*>temp;
                vector<int>val;
                for (int i = 0; i < size; ++i) {
                    TreeNode* front = q.front();
                    q.pop();
                    temp.push(front);
                    val.push_back(front->val);
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
                reverse(val.begin(),val.end());
                int i=0;
                while(!temp.empty()){
                    auto t=temp.front(); temp.pop();
                    t->val=val[i++];
                }
            } else {
                for (int i = 0; i < size; ++i) {
                    TreeNode* front = q.front();
                    q.pop();
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
            }
            level = !level;
        }
        return root;
    }
};
