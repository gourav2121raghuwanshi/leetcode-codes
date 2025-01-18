class Solution {
    int ans;
    void dfs(int node, vector<int>& cycle, vector<int>& edges,
             unordered_set<int>& vis) {
        if (node == -1)
            return;
        if (vis.count(node)) {
            int c = -1;

            for (int i = 0; i < cycle.size(); ++i) {
                if (cycle[i] == node) {
                    c = i;
                    break;
                }
            }
            if (c == -1)
                return;
            int curr_len = cycle.size() - c;
            ans = max(ans, curr_len);
            return;
        }
        vis.insert(node);
        cycle.push_back(node);
        dfs(edges[node], cycle, edges, vis);
    }

public:
    int longestCycle(vector<int>& edges) {
        unordered_set<int> vis;
        int n = edges.size();

        ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis.count(i)) {
                vector<int> cycle;
                dfs(i, cycle, edges, vis);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};