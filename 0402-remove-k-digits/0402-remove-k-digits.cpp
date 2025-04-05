class Solution {
public:
    string removeKdigits(string num, int k) {
        // string ans="";
        stack<char> st;
        for (auto& i : num) {
            while (k && !st.empty() && i < st.top()) {
                --k;
                st.pop();
            }
            st.push(i);
        }

        while (k>0 && !st.empty()) {
            --k;
            st.pop();
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0') ans.pop_back();
        if(ans.empty()) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};