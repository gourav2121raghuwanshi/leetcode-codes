/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> mp;

    TreeNode*solve(int is,int ie,int ps,int pe,vector<int>& inorder, vector<int>& postorder){
        if(is>ie || ps>pe) return NULL;
        if(is==ie) return new TreeNode(inorder[is]);

        TreeNode*root=new TreeNode(postorder[pe]);
        int idx=mp[postorder[pe]];
        // int len=ie-idx;
        int leftLen=idx-is;
        root->left=solve(is,idx-1,ps,ps+leftLen-1 ,inorder,postorder);
        root->right=solve(idx+1,ie,ps+leftLen ,pe-1,inorder,postorder);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            mp[inorder[i]] = i;
        }
        return solve(0,n-1,0,n-1,inorder,postorder);
    }
};