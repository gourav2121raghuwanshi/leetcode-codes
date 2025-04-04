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
    TreeNode* lca(TreeNode*root,TreeNode*a,TreeNode*b){
        if(!root) return root;
        if(root == a || root ==b) return root;
      
        TreeNode*left=lca(root->left,a,b);
        TreeNode*right=lca(root->right,a,b);
        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
        return NULL;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*a=nullptr;
        TreeNode*b=nullptr;
        while(!q.empty()){
            int s=q.size();
            int c=0;
            while(s--){
                auto f=q.front(); q.pop();
                if(c==0) a=f;
                b=f;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                ++c;
            }
        }
        
        if(a==b) return a;
        else return lca(root,a,b);
    }
};