class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> freq(26, 0);
        for (auto& i : s) {
            ++freq[i - 'a'];
        }
        vector<int> taken(26, 0);

        for (auto& i : s) {
            cout<<ans<<" ,";
            if (ans.empty() || ans.back() < i) {
                if (!taken[i - 'a']) {
                    ans.push_back(i);
                    --freq[i - 'a'];
                    taken[i - 'a'] = true;
                }
            } else {
                if (taken[i - 'a']) {
                    --freq[i - 'a'];  cout<<ans<<endl;
                    continue;
                }
                while (!ans.empty() && ans.back() >= i &&
                    freq[ans.back() - 'a'] > 0) {
                    taken[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(i);
                taken[i - 'a'] = true;
                --freq[i - 'a'];
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};