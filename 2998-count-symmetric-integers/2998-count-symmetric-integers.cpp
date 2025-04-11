class Solution {
    bool checkSymm(string s) {
        if(s.size()&1) return false;
        int i = 0;
        int j = s.size() - 1;
        int ss=0;
        int es=0;
        while (i < j) {
            ss+=s[i]-'0';
            es+=s[j]-'0';
            ++i, --j;
        }
        return ss==es;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int c = 0;
        for (int i = low; i <= high; ++i) {
            if (checkSymm(to_string(i)))
                ++c;
        }
        return c;
    }
};