class Solution {
    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i, --j;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(int i, string& s, vector<string>& v) {
        if (i >= s.size()) {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            // temp.push_back(s[j]);
            if (isPal(s, i, j)) {
                v.push_back(s.substr(i, j - i + 1));
                solve(j + 1, s, v);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0, s, v);
        return ans;
    }
};