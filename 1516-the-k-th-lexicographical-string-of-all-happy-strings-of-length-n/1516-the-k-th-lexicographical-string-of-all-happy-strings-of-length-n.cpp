class Solution {
    string ans;
    bool solve(string s, int &n, int &k) {
        if (s.size() == n) {
            --k;
            if (k == 0) {
                ans = s;
                return 1;
            }
            return 0;
        }
        if (s.empty()) {
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                s.push_back(ch);
                if (solve(s, n , k))
                    return 1;
                s.pop_back();
            }
        } else {
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                if (s.back() != ch) {
                    s.push_back(ch);
                    if (solve(s, n, k))
                        return 1;
                    s.pop_back();
                }
            }
        }
        return false;
    }

public:
    string getHappyString(int n, int k) {
        solve("", n, k);
        return ans;
    }
};