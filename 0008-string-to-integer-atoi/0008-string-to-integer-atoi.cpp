class Solution {
    void solve(long long &ans, string &s, int i) {
        if(i >= s.size() || !isdigit(s[i])) return;

        int digit = s[i] - '0';

        // Only clamp here to prevent overflow — don't return yet
        if(ans > (LLONG_MAX - digit) / 10) {
            ans = LLONG_MAX; // Use this temporarily; clamp later
            return;
        }

        ans = ans * 10 + digit;
        solve(ans, s, i + 1);
    }

public:
    int myAtoi(string s) {
        long long ans = 0;
        bool neg = false;
        int i = 0;

        // Skip leading whitespaces
        while(i < s.size() && s[i] == ' ') ++i;

        // Handle sign
        if(i < s.size() && s[i] == '-') {
            neg = true;
            ++i;
        } else if(i < s.size() && s[i] == '+') {
            ++i;
        }

        // Parse digits recursively
        solve(ans, s, i);

        // Apply sign AFTER full parsing
        if(neg) ans = -ans;

        // Clamp to 32-bit signed int bounds
        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;

        return (int)ans;
    }
};
