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
    int ans=0;
    void solve(TreeNode*root,vector<int>&freq){
        if(!root)
            return ;
        ++freq[root->val];
        if(!root->left && !root->right){
            int cnt=0;
            for(auto&i:freq){
                if(i&1) ++cnt;
            }
            if(cnt<=1) ++ans;
        }
        
        solve(root->left,freq);
        solve(root->right,freq);
        --freq[root->val];
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return 0;
        vector<int>freq(10,0);
        solve(root,freq);
        return ans;
    }
};