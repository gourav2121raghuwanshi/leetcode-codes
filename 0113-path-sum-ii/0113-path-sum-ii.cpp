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
    vector<vector<int>>ans;
public:
    void solve(TreeNode*root,int ts,vector<int>&v){
        if(!root) return;
        if(!root->left && !root->right){
            if(ts-root->val==0){
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        solve(root->left,ts-root->val,v);
        solve(root->right,ts-root->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        vector<int>v;

        solve(root,ts,v);
        return ans;
    }
};