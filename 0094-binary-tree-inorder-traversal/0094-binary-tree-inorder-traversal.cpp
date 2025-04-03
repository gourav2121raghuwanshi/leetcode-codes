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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root=root->right;
            }else{
                TreeNode*pred=root->left;
                while(pred->right && pred->right!=root)pred=pred->right;
                pred->right=root;
                TreeNode*temp=root->left;
                root->left=NULL;
                root=temp;
            }
        }
        return ans;
    }
};