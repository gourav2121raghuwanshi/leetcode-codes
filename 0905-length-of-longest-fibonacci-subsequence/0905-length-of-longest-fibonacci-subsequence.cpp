class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> mp;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Store index of each element
        for (int i = 0; i < n; ++i) {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < n && (n - i + 1 > ans); ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dp[i][j] != -1) continue; // Already computed

                int req = arr[i] + arr[j];
                int idx = j, idx1 = i;
                int l = 2;  

                while (mp.find(req) != mp.end() && mp[req] > idx) {
                    int k = mp[req];

                    // Memoize the result
                    if (dp[idx][k] != -1) {
                        l = dp[idx][k] + 1;
                        break;
                    }

                    dp[idx][k] = l + 1;
                    idx1 = idx;
                    idx = k;
                    req = arr[idx1] + arr[idx];  
                    ++l;
                }

                if (l > 2) ans = max(ans, l);
            }
        }
        return ans;
    }
};
