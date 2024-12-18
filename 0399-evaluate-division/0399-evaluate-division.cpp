class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    double dfs(string start, string end, unordered_set<string>& vis, double val) {
        if (start == end)
            return val;
        vis.insert(start);

        for (auto& j : adj[start]) {
            if (!vis.count(j.first)) {
                vis.insert(j.first);
                double ans = dfs(j.first, end, vis, val * j.second);
                if (ans != -1)
                    return ans;
            }
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = values.size();
        for (int i = 0; i < n; ++i) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ans;

        for (auto& i : queries) {
            string a = i[0];
            string b = i[1];
            if(!adj.count(a)){
                ans.push_back(-1);
                continue;
            }
            unordered_set<string> vis;
            double va = 1;
            double val = dfs(a, b, vis, va);
            ans.push_back(val);
        }
        return ans;
    }
};