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
    TreeNode*first=NULL;
    TreeNode*next=NULL;
    TreeNode*prev=NULL;
    void solve(TreeNode*root){
        if(!root)return;
        solve(root->left);
        if(prev){
            if(root->val<prev->val){
            if(first)next=root;
            else{
                first=prev;
                next=root;
            }
            }
        }
        prev=root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
        if(first){
            swap(first->val,next->val);
        }
    }
};