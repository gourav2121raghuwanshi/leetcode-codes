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
    TreeNode*solve(int &i,int mini,int maxi,vector<int>& preorder)
{
    if(i>=preorder.size()) return nullptr;
    if(preorder[i]<=mini || preorder[i]>=maxi) return nullptr;
    TreeNode*root=new TreeNode(preorder[i++]);
    root->left=solve(i,mini,root->val,preorder);
    root->right=solve(i,root->val,maxi,preorder);
    return root;

}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
    if(preorder.empty())     return NULL;
    return solve(i,INT_MIN,INT_MAX,preorder);
    }
};