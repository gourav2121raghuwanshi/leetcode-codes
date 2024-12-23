class Solution {
    TreeNode* solve(TreeNode* root, unordered_set<int>& st,
                    vector<TreeNode*>& ans) {
        if (!root)
            return nullptr;
        root->left = solve(root->left, st, ans);
        root->right = solve(root->right, st, ans);

        if (st.count(root->val)) {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            if (l) {
                ans.push_back(l);
            }
            if (r)
                ans.push_back(r);
            return NULL;

        } else {
            return root;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
            return {};
        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        solve(root, st, ans);
        if (!st.count(root->val)) {
            ans.push_back(root);
        }
        return ans;
    }
};