class Solution {
    void solve(TreeNode* root,int &maxi,int c,bool left){
        if(!root) return ;
        maxi=max(maxi,c);
        if(left){
            solve(root->right,maxi,c+1,false);
            solve(root->left,maxi,1,true);
        }else{
            solve(root->left,maxi,c+1,true);
            solve(root->right,maxi,1,false);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        int maxi=0;
        solve(root,maxi,0,true);
        return maxi;
    }
};