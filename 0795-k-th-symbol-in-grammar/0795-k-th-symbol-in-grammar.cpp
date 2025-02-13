class Solution {
    int ans;
    int solve(int n, int k) {
        if (n == 1 && k == 0) {
            return 0;
        }
        int mid =
            pow(2, n - 1); // as the length increase by factor of 2 each Time

        if (k < mid) {
            return solve(n - 1, k);
        } else
            return !solve(n, k - mid);
    }

public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        --k;
        return solve(n, k);
    }
};