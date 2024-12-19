class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a.find(b) != string::npos)
            return 1;
        int cnt = 1;
        string x = a;
        while (a.size() < b.size()) {
            ++cnt;
            a += x;
        }
        if (a.find(b) != string::npos) {
            return cnt;
        }
        a += x;
        ++cnt;
        if (a.find(b) != string::npos) {
            return cnt;
        }

        a += x;
        ++cnt;
        if (a.find(b) != string::npos) {
            return cnt;
        }

        return -1;
    }
};