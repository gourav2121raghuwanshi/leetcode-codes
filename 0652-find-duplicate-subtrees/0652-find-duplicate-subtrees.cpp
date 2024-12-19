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
    vector<TreeNode*> ans;
    string solve(TreeNode*root,unordered_map<string,int>&mp){
        if(!root) return "*";

        string curr=to_string(root->val)+","+solve(root->left,mp)+","+solve(root->right,mp);
        if(mp[curr]==1) ans.push_back(root);
        ++mp[curr];
        return curr;

    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        solve(root,mp);
        return ans;
    }
};