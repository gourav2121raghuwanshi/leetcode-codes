class Solution {
    bool solve(long long p1, long long p2, const string& num, int index, bool match) {
        if (index == num.size() && p1 != -1 && p2 != -1 && match) 
            return true;
        long long n = 0;
        int cnt=0;
        for (int j = index; j < num.size(); ++j) {
            
            if (j > index && num[index] == '0') 
                break;
            n = n * 10 + (num[j] - '0');
            ++cnt;
            if(cnt>num.size()/2+1) break;
            if (p1 == -1) {
                if (solve(n, p2, num, j + 1, false)) 
                    return true;
            } else if (p2 == -1) {
                if (solve(p1, n, num, j + 1, false)) 
                    return true;
            } else if (p1 + p2 == n) {
                if (solve(p2, n, num, j + 1, true)) 
                    return true;
            } else if (p1 + p2 < n) {
                break;
            }
        }
        return false;
    }

public:
    bool isAdditiveNumber(string num) {
        return solve(-1, -1, num, 0, false);
    }
};
