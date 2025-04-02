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
    stack<TreeNode*>left;
    stack<TreeNode*>right;
    void l(TreeNode*root){
        while(root){
            left.push(root);
            root=root->left;
        }
    }
     void r(TreeNode*root){
        while(root){
            right.push(root);
            root=root->right;
        }
    }

public:
    bool findTarget(TreeNode* root, int k) {
        l(root);
        r(root);
        while(!left.empty() && !right.empty()){
            int v1=left.top()->val;
            int v2=right.top()->val;
            if(v1==v2) return false;
            if(v1+v2==k) return true;
            else if(v1+v2>k){
                auto t=right.top(); right.pop();
                r(t->left);
            }else{
                auto t=left.top(); left.pop();
                l(t->right);
            }
        }
        return false;
    }
};