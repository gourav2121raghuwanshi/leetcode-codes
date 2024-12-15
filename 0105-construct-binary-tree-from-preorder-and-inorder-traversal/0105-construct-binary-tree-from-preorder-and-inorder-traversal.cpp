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
     unordered_map< int, int> mp;
     TreeNode*solve(int is,int ie,int ps,vector<int>& preorder, vector<int>& inorder){
        if(is>ie || ps>=preorder.size()) return NULL;
        if(is==ie) return new TreeNode(inorder[is]);

        TreeNode*root=new TreeNode(preorder[ps]);
        int idx_in=mp[preorder[ps]];

        root->left=solve(is, idx_in-1, ps+1,preorder,inorder);
        root->right=solve(idx_in+1,ie,idx_in-is+1+ps ,preorder,inorder);
        return root;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]]=i;
        }
        return solve(0,n-1,0,preorder,inorder);
    }
};