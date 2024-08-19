class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        if (n == 2)
            return 2;
        vector<int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int fac = i / 2;
            while (fac >= 1) {
                if (i % fac == 0) {
                    int copy=1;
                    int paste=(i / fac - 1);
                    dp[i] = dp[fac] +  copy + paste;
                    break;
                }
                --fac;
            }
        }

        return dp[n];
    }
};