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
    int leftHeight(TreeNode*root){
        if(!root) return 0;
        return 1+leftHeight(root->left);
    }
    int rightHeight(TreeNode*root){
        if(!root) return 0;
        return 1+rightHeight(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftheight=leftHeight(root->left);
        int rightheight=rightHeight(root->right);
        if(leftheight==rightheight) return (1<<(rightheight+1))-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};