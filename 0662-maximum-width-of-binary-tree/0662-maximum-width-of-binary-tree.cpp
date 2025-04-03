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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        int last=0;
        while(!q.empty()){
            int first=q.front().second;
            int sz=q.size();
            int lst=-1;
            while(sz--){
                auto front=q.front();
                q.pop();
                TreeNode*node=front.first;
                int cnt=front.second;
                if(node->left) q.push({node->left,2*cnt+1-last});
                if(node->right)q.push({node->right,2*cnt+2-last});
                lst=cnt;
            }
            last=lst;
            // cout<<first<<" "<<lst<<endl;
            ans=max(ans,lst-first+1);
        }

        return ans;
    }
};