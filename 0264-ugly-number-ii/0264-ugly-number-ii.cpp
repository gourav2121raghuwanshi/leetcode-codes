class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;

        int two = 0;
        int three = 0;
        int five = 0;
        int dp[1700];
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            int ntwo = dp[two] * 2;
            int nthree = dp[three] * 3;
            int nfive = dp[five] * 5;

            int next = min({ntwo, nthree, nfive});
            dp[i] = next;
            if (ntwo == next)
                ++two;
            if (nthree == next)
                ++three;
            if (nfive == next)
                ++five;
        }
        return dp[n - 1];
    }
};