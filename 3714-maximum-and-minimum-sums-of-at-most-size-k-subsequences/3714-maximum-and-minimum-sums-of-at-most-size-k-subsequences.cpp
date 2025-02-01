class Solution {
    const int MOD = 1e9 + 7;
    long long modPower(long long x, long long y) {
        long long res = 1;
        x = x % MOD;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % MOD;
            y = y >> 1;
            x = (x * x) % MOD;
        }
        return res;
    }

    vector<long long> factorial;
    vector<long long> inverseFactorial;
    void preComputeFactorial_and_InverseFactorial(int n) {
        factorial.resize(n + 1);
        inverseFactorial.resize(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = (factorial[i - 1] * 1LL * i) % MOD;
        }

        inverseFactorial[n] = modPower(factorial[n], MOD - 2);

        for (int i = n - 1; i >= 0; --i) {
            inverseFactorial[i] =
                (inverseFactorial[i + 1] * 1LL * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r > n || r < 0)
            return 0;
        return ((factorial[n]%MOD * inverseFactorial[r]%MOD)%MOD * inverseFactorial[n - r]%MOD) %
               MOD;
    }

public:
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        preComputeFactorial_and_InverseFactorial(n);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for(int size=1;size<=k;++size){
                 int remaining_Number_of_ele_in_which_this_is_maxi = i;
            int remaining_Number_of_ele_in_which_this_is_mini = n - (i + 1);

            ans = (ans +
                  (nums[i] *1LL*
                   nCr(remaining_Number_of_ele_in_which_this_is_maxi, size - 1))%MOD) %
                 MOD; 
            ans = (ans +
                   (nums[i] *1LL* nCr(remaining_Number_of_ele_in_which_this_is_mini,
                                  size - 1))%MOD) %
                  MOD; // ncr
            }
           
        }
        return ans;
    }
};