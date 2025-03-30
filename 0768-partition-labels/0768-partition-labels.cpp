class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_set<char> curr;
        int n = s.size();

        vector<int> freq(26, 0);
        for (auto& i : s) {
            ++freq[i - 'a'];
        }
        vector<int> ans;
        int last = -1;
        for (int j = 0; j < s.size(); ++j) {
            char i = s[j];
            curr.insert(i);
            --freq[i - 'a'];
            bool f = 1;
            if (freq[i - 'a'] == 0) {
                for (auto& jj : curr) {

                    if (freq[jj - 'a'] > 0) {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    int val = j;
                    if (last != -1)
                        val -= last;
                    if(ans.empty())
                    ans.push_back(val + 1);
                    else ans.push_back(val);
                    last = j;
                    curr.clear();
                }
            }
        }
        return ans;
    }
};