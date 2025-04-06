class Solution {
    double solve(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        double half = solve(x, n / 2);

        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }

public:
    double myPow(double x, int n) {
        if (x == 1.0) return 1.0;

        long long N = n;
        bool neg = false;

        if (N < 0) {
            neg = true;
            N = -N;
        }

        double ans = solve(x, N);
        return neg ? 1.0 / ans : ans;
    }
};
