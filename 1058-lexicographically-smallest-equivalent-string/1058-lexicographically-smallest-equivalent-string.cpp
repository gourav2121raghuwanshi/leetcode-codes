class Solution {
    unordered_map<char, vector<char>> adj;
    unordered_set<char> st;
    char dfs(char mini) {
        if (st.count(mini))
            return mini;
        // cout<<mini<<" ,";
        st.insert(mini);
        char curr = mini;
        for (auto& i : adj[curr]) {
            mini = min(mini, dfs(i));
        }
        return mini;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < s1.size(); ++i) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        unordered_map<char, char> miniChar;
        for (auto& i : baseStr) {
            if (miniChar.count(i)) {
                ans.push_back(miniChar[i]);
            } else {
                char mini = i;
                st.clear();
                mini = dfs(mini);
                ans.push_back(mini);
                miniChar[i] = mini;
            }
        }
        return ans;
    }
};