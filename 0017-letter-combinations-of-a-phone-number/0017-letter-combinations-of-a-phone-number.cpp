class Solution {
    vector<string> ans;
    vector<string> keypad;
    void solve(string s, int i, string& dig) {
        if (i >= dig.size()) {
            if (!s.empty())
                ans.push_back(s);
            return;
        }
        int idx = dig[i] - '0';
        for (auto& j : keypad[idx]) {
            solve(s + j, i + 1, dig);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        keypad = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        solve("", 0, digits);
        return ans;
    }
};