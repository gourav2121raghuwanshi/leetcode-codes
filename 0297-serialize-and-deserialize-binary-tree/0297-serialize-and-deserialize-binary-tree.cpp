/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto front=q.front(); q.pop();
            if(front) ans+=to_string(front->val)+":";
            else ans+="#:";
            if(front){
                q.push(front->left);
                q.push(front->right);
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        return NULL;
        queue<TreeNode*>q;
        stringstream ss(data);
        string str;
        getline(ss,str,':');
        TreeNode*root=new TreeNode(stoi(str));
    
        q.push(root);
        while(!q.empty()){
            auto front=q.front(); q.pop();
            getline(ss,str,':');
            if(str=="#"){
                front->left=nullptr;
            }else{
                front->left=new TreeNode(stoi(str));
                q.push(front->left);
            }
            getline(ss,str,':');
            if(str=="#"){
                front->right=nullptr;
            }else{
                front->right=new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));