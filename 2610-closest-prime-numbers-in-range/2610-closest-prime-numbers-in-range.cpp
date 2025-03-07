class Solution {
    vector<int> primes;
    void getPrimes(int n) {
        primes.resize(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i*i <= n; ++i) {
            if (primes[i] == 0)
                continue;
            for (int j = i+i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

public:
    vector<int> closestPrimes(int left, int right) {
        getPrimes(right);
        vector<int> p;
        for (int i = 0; i <= right; i++) {
            if (primes[i])
                p.push_back(i);
        }
        int last = -1;
        int ans = 1e9;
        vector<int> v = {-1, -1};
        for (auto& i : p) {
            if (i >= left && i <= right) {
                if (last == -1)
                    last = i;
                else {
                    if (ans > i - last) {
                        v = {last, i};
                        ans = min(ans, i - last);
                    }
                }
                last = i;
            }
        }
        return v;
    }
};