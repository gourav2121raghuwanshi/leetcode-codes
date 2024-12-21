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
class CBTInserter {
public:
    vector<TreeNode*>v;
    CBTInserter(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto f=q.front(); q.pop();
            v.push_back(f);
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
    
    int insert(int val) {
            int n=v.size();
            TreeNode*temp=new TreeNode(val);
            v.push_back(temp);
            int idx=(n-1)/2;
            if(n&1){
                v[idx]->left=temp;
            }else v[idx]->right=temp;
            return v[idx]->val;
    }
    
    TreeNode* get_root() {
        return v[0];    
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */