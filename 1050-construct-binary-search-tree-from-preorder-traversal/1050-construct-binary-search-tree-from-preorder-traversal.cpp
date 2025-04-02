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
    int n;
    TreeNode*solve(int &i,vector<int>&pre,int mini,int maxi){
        if(i>=n) return NULL;
        if(pre[i]>=maxi || pre[i]<=mini) return NULL;
        TreeNode*root=new TreeNode(pre[i]);
        ++i;
        root->left=solve(i,pre,mini,root->val);
        root->right=solve(i,pre,root->val,maxi);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n=preorder.size();
        if(n==0) return nullptr;
        int i=0;
        return solve(i,preorder,INT_MIN,INT_MAX);
    }
};