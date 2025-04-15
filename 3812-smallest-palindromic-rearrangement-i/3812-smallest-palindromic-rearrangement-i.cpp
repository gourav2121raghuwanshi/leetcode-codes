class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (auto& i : s) {
            ++freq[i - 'a'];
        }
        string start;
        string end;
        char mid;
        int midLen = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i]) {
                if (freq[i] & 1) {
                    mid = i + 'a';
                    midLen = freq[i];
                    if(midLen>1){
                        string a=string(midLen/2,mid);
                        start+=a;
                        end=a+end;   
                    }
                    midLen=1;
                } else {
                    string s(freq[i] / 2, i + 'a');
                    start += s;
                    end = s + end;
                }
            }
        }
        if (midLen == 0)
            return start + end;

        return start + mid + end;
    }
};