class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> ans;
        set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(i);
        for (auto& i : queries) {
            int a = i[0];
            int b = i[1];
            auto lb = st.lower_bound(a + 1);
            auto ub = st.lower_bound(b);
            st.erase(lb, ub);
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};