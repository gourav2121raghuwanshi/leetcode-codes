
class Solution {
    // int h(TreeNode*root){
    //     if(!root) return 0;
    //     return 1+max(h(root->left),h(root->right));
    // }
    // int ans;
    // int solve(TreeNode*root){
    //     if(!root) return 0;

    //     int lh=h(root->left);
    //     int rh=h(root->right);

    //     return max({lh+rh,solve(root->left),solve(root->right)});
    // }
    pair<int,int> solve(TreeNode*root){
        if(root==nullptr) return make_pair(0,0);
        pair<int,int>l=solve(root->left);
        pair<int,int>r=solve(root->right);

        return make_pair(1+max(l.first,r.first),max({l.second,r.second,l.first+r.first}));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
   
        return solve(root).second;
    
    }
};