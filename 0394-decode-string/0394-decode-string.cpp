class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ']') {
                ans.push_back(s[i]);
            } else {
                string temp = "";
                while (!ans.empty() && ans.back() != '[') {
                    temp = ans.back() + temp;
                    ans.pop_back();
                }
                if (!ans.empty())
                    ans.pop_back();
                int c = 1;
                int val = 0;
                while (!ans.empty() && isdigit(ans.back())) {
                    val = (ans.back() - '0') * c + val;
                    c *= 10;
                    ans.pop_back();
                }
                string rep = "";
                while (val--) {
                    rep += temp;
                }
                ans = ans + rep;
            }
        }
        return ans;
    }
};