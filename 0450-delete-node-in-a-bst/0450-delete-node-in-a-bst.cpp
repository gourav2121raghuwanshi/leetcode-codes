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
    TreeNode*predecessor(TreeNode*root){
        TreeNode*temp=root->left;
        while(temp->right) temp=temp->right;
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }else if(!root->left){
                TreeNode*curr=root;
                TreeNode*right=root->right;
                delete curr;
                return right;
            }else if(!root->right){
                TreeNode*curr=root;
                TreeNode*left=root->left;
                delete curr;
                return left;
            }else{
                TreeNode*pred=predecessor(root);
                root->val=pred->val;
                pred->val=key;
                root->left=deleteNode(root->left,key);
            }
        }
        return root;
    }
};