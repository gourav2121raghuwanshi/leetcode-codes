class Solution {
    string ans = "";
    void solve(int n, string& s, string& curr, int& c, int k) {
        if (!ans.empty())
            return;
        if (n == 0) {
            ++c;
            if (c == k) {
                ans = curr;
            }
            return;
        }

        for (auto& i : s) {
            if (curr.empty() || curr.back() != i) {
                curr.push_back(i);
                solve(n - 1, s, curr, c, k);
                curr.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        string s = "abc";
        string curr;
        int c = 0;
        solve(n, s, curr, c, k);
        return ans;
    }
};
