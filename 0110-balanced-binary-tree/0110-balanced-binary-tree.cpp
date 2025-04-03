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
    // int h(TreeNode*root){
    //     if(!root) return 0;
    //     return 1+max(h(root->left),h(root->right));
    // }
    // bool solve(TreeNode*root){
    //     if(!root) return true;

    //     int h1=h(root->left);
    //     int h2=h(root->right);

    //     return abs(h1-h2)<=1 && solve(root->left) && solve(root->right);
    // }
    pair<int,bool>solve(TreeNode*root){
        if(!root) return make_pair(0,true);

        pair<int,bool>l=solve(root->left);
        pair<int,bool>r=solve(root->right);
        pair<int,bool>ans;
        ans.first=1+max(l.first,r.first);
        ans.second = abs(l.first-r.first)<=1 && l.second && r.second;
        return ans;

    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).second;

    }
};