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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root)  return nullptr;
       if(root==p || root==q) return root;

       TreeNode*left=lowestCommonAncestor(root->left,p,q);
       TreeNode*right=lowestCommonAncestor(root->right,p,q);
       if(left && right) return root;
       if(left) return left;
       if(right) return right;
       return nullptr;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*left=root;
        TreeNode*right=root;
        while(!q.empty()){
            int size=q.size(); 
            for(int i=0;i<size;i++){
                auto front=q.front(); q.pop();
               if(i==0) left=front;
               if(i==size-1) right=front;
                if(front->left){ q.push(front->left);  }
                if(front->right){ q.push(front->right); }
            }
            
        }
        
        return lowestCommonAncestor(root,left,right);
    }
};