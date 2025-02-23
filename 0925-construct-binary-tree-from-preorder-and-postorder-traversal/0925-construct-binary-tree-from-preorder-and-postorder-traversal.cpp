/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(int pres, int pree, int posts, int poste, vector<int>& preorder,
                vector<int>& postorder) {
        if (pres > pree || posts > poste)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pres]);
        if (pres == pree)
            return root;

        int postIndex = posts;

        while (postorder[postIndex] != preorder[pres + 1])
            postIndex++;

        int len = postIndex - posts + 1;

        root->left =
            f(pres + 1, pres + len, posts, postIndex, preorder, postorder);

        root->right = f(pres + 1 + len, pree, postIndex + 1, poste - 1,
                        preorder, postorder);
                        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();
        return f(0, n - 1, 0, n - 1, preorder, postorder);
    }
};

// parent at pre start

// pre  NLR
// post LRN
// 
// pre : [1,2,4,5,3,6,7]
// post: [4,5,2,6,7,3,1]
