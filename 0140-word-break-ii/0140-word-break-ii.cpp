class Solution {
public:
    void solve(int i, string s, vector<string>& ans, string &curr,
               unordered_set<string>& st) {
                cout<<curr<<endl;
        if (i >= s.size()) {
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for (int j = i; j < s.size(); j++) {
            temp.push_back(s[j]);
            if (st.count(temp)) {
                string to_sent=curr;
                if (to_sent.empty())
                    to_sent = temp;
                else
                    to_sent = to_sent + " " + temp;
                solve(j+1, s, ans, to_sent, st);
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto& i : wordDict)
            st.insert(i);
        vector<string> ans;
        string curr;
        solve(0, s, ans, curr, st);
        return ans;
    }
};