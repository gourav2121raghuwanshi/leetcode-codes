class Solution {
    const int mod = 1e9 + 7;
    // long long solve(long long i,long long n){
    //     if(i>=n) return 1;
    //     if(i%2==0){
    //             return (5*1LL*solve(i+1,n)%mod)%mod;
    //     }else return (4%mod*(1LL)*solve(i+1,n)%mod)%mod;
    // }
    long long powL(long long val, long long pow) {
        if (val == 1)
            return 1;
        if (pow == 1)
            return val;
        long long ans = 1;
        while (pow > 0) {
            if (pow & 1) {
                ans = (ans * val) % mod;
                --pow;
            } else {
                val = (val * val) % mod;
                pow /= 2;
            }
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        // vector<int>primes=
        // return solve(0,n);
        long long odd = n / 2;
        long long even = (n + 1) / 2;

        return (powL(5, even) * powL(4, odd)) % mod;
    }
};