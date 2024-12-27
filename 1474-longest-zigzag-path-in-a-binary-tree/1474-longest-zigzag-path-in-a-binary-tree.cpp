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
    map<pair<TreeNode*,int>,int>mp;
    int solve(TreeNode*root,int dir){
        if(!root) return 0;
        if(mp.count({root,dir})) return mp[{root,dir}];
        if(dir){
            return  mp[{root,dir}] = 1+solve(root->left,false);
        }else     return  mp[{root,dir}]= 1+solve(root->right,true);
    }
    
    int solve2(TreeNode* root) {
        if(!root) return 0;
        int left=solve2(root->right);
        int right=solve2(root->left);
        int current=max(solve(root,false),solve(root,true));
        return max({current,left,right});
    }
public:
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        return max(0,solve2(root)-1);
    }
};