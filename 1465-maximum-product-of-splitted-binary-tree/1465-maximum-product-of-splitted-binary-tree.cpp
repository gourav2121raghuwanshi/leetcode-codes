class Solution {
    const int mod = 1e9 + 7;
    long long totalSum = 0;
    long long maxProductVal = 0;

    long long calculateTotalSum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + calculateTotalSum(root->left) +
               calculateTotalSum(root->right);
    }

    long long calculateSubtreeSums(TreeNode* root) {
        if (!root)
            return 0;

        long long subtreeSum = root->val + calculateSubtreeSums(root->left) +
                               calculateSubtreeSums(root->right);

        long long remainingSum = totalSum - subtreeSum;
        maxProductVal = max(maxProductVal, (subtreeSum) * (remainingSum));

        return subtreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        if (!root)
            return 0;

        totalSum = calculateTotalSum(root);

        calculateSubtreeSums(root);

        return maxProductVal % mod;
    }
};
