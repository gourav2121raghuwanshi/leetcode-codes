class Solution {
    TreeNode*solve(TreeNode*root){
        if(!root) return nullptr;
        root->left=solve(root->left);
        root->right=solve(root->right);

        if(root->val==0 && !root->left && !root->right) return nullptr;
        return root;
    }   
public:
    TreeNode* pruneTree(TreeNode* root) {
       if(!root)  return root;
       return solve(root);
    }
};