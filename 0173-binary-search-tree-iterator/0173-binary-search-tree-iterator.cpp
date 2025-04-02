
class BSTIterator {
public:
    stack<TreeNode*>st;
    void left(TreeNode*root){
            while(root){
                st.push(root);
                root=root->left;
            }
        }
    BSTIterator(TreeNode* root) {
        left(root);
    }
    
    int next() {
        TreeNode*t=st.top();
        st.pop();
        left(t->right);
        return t->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */