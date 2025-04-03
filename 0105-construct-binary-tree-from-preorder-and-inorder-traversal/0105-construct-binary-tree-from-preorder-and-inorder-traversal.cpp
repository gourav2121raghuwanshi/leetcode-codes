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
    unordered_map<int,int>mp;
    TreeNode*solve(int ps,int is,int ie,vector<int>& preorder, 
    vector<int>& inorder){
        if(is>ie || is>=inorder.size() || ps>=preorder.size()) return NULL;
        if(is==ie) return new TreeNode(inorder[is]);
        
        TreeNode*root= new TreeNode(preorder[ps]);
        int idx=mp[preorder[ps]];
        int leftLen=idx-is+1;
        root->left=solve(ps+1,is,idx-1,preorder,inorder);
        root->right=solve(ps+leftLen,idx+1,ie,preorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        
        for(int i=0;i<n;++i){
            mp[inorder[i]]=i;
        }
        return solve(0,0,n-1,preorder,inorder);
    }
};