class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.size() > str1.size())
            return false;
        if (str1 == str2)
            return true;

        int i = 0;
        for (int j = 0; j < str1.size(); ++j) {
            if (i >= str2.size())
                break;

            if (str1[j] == str2[i] || str2[i] == str1[j] + 1 ||
                (str2[i] == 'a' && str1[j] == 'z')) {
                ++i;
            }
        }
        return i >= str2.size();
    }
};