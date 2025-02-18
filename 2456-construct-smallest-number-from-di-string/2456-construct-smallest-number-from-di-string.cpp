class Solution {
    int n;
    bool solve(int idx, string& ans, vector<bool>& avail, string& pattern) {
        if (idx>=pattern.size())
            return true;

        if (pattern[idx] == 'D') {
            int curr = ans.back() - '0';
            for (int j = 1; j < curr; ++j) {
                if (avail[j]) {
                    ans.push_back(j + '0');
                    avail[j] = false;
                    if (solve(idx + 1, ans, avail, pattern))
                        return true;
                    avail[j] = true;
                    ans.pop_back();
                }
            }
        } else {
            int curr = ans.back() - '0';
            for (int j = curr + 1; j < n; ++j) {
                if (avail[j]) {
                    ans.push_back(j + '0');
                    avail[j] = false;
                    if (solve(idx + 1, ans, avail, pattern))
                        return true;
                    avail[j] = true;
                    ans.pop_back();
                }
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        n = pattern.size() + 2;
        vector<bool> avail(n, true);
        string ans;
        for (int i = 1; i < n; ++i) {
            ans.push_back(i + '0');
            avail[i] = false;
            if (solve(0, ans, avail, pattern))
                return ans;
            avail[i] = true;
            ans.pop_back();
        }
        return ans;
    }
};