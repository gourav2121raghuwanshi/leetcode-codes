
class Solution {
    vector<bool> primes; // Use vector<bool> instead of vector<int>
    
    void getPrimes(int n) {
        primes.assign(n + 1, true); // Use assign() to avoid reallocation
        primes[0] = primes[1] = false; // 0 and 1 are not prime
        
        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) { // Start marking from i * i
                    primes[j] = false;
                }
            }
        }
    }

public:
    vector<int> closestPrimes(int left, int right) {
        getPrimes(right); // Generate primes up to 'right'
        
        vector<int> p;
        for (int i = left; i <= right; i++) { // Iterate only from left to right
            if (primes[i])
                p.push_back(i);
        }

        if (p.size() < 2) return {-1, -1}; // If fewer than 2 primes, return {-1, -1}

        int last = p[0], ans = 1e9;
        vector<int> v = {-1, -1};
        
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - last < ans) {
                ans = p[i] - last;
                v = {last, p[i]};
            }
            last = p[i]; // Move last to current prime
        }
        
        return v;
    }
};
