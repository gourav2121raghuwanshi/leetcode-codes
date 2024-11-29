class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                int curr = s[i] - 'a'; // Current character index
                int req = t[i] - 'a';  // Required character index

                // Forward (next) distance
                int d1 = (req - curr + 26) % 26;

                // Backward (previous) distance
                int d2 = (curr - req + 26) % 26;

                // Calculate next and previous costs
                long long nc = 0, pc = 0;

                for (int j = 0; j < d1; ++j) {
                    nc += nextCost[(curr + j) % 26];
                }

                for (int j = 0; j < d2; ++j) {
                    pc += previousCost[(curr - j + 26) % 26];
                }

                // Add the minimum of both costs
                ans += min(nc, pc);
            }
        }
        return ans;
    }
};
