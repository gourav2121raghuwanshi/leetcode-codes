class Solution {

    bool check(int j,string s,int req) {
        if(j==s.size()){
            return req==0;
        }
        int sum = 0;
        for (int i = j; i < s.size(); ++i) {
            char ch = s[i];
            sum = sum * 10 + (ch - '0');
            if(check(i+1,s,req-sum)) return 1;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (check(0, to_string(i * i), i))
                ans+=i*i;
        }
        return ans;
    }
};