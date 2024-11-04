class Solution {
public:
    string compressedString(string word) {
        int c = 1;
        string ans = "";
        int n = word.size();
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1])
                ++c;
            else {
                while (c >= 1) {
                    char val;
                    if (c >= 9) {
                        c -= 9;
                        val = '9';
                    } else {
                        val = c + '0';
                        c = 0;
                    }
                    ans.push_back(val);
                    ans.push_back(word[i - 1]);
                }
                c = 1;
            }
        }
        if (c) {
            while (c >= 1) {
                char val;
                if (c >= 9) {
                    c -= 9;
                    val = '9';
                } else {
                    val = c + '0';
                    c = 0;
                }
                ans.push_back(val);
                ans.push_back(word[n - 1]);
            }
        }
            return ans;
        }
    };