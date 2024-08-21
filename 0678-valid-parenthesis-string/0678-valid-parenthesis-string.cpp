class Solution {
    int dp[101][101];
public:
    bool solve(int idx, int open, string& s) {
        if (open < 0) return false;
        if (idx == s.size()) return (open == 0);
        if (dp[idx][open] != -1) return dp[idx][open];
        
        bool ans = false;
        if (s[idx] == '*') {
            ans = ans || solve(idx + 1, open + 1, s);
            if(ans) return true;
            ans = ans || solve(idx + 1, open - 1, s);
              if(ans) return true;
            ans = ans || solve(idx + 1, open, s);
              if(ans) return true;
          
        } 
        else if (s[idx] == '(') {
            ans = ans || solve(idx + 1, open + 1, s);
              if(ans) return true;
        } else {
            ans = ans || solve(idx + 1, open - 1, s);
              if(ans) return true;
        }
        return dp[idx][open] = ans;
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};