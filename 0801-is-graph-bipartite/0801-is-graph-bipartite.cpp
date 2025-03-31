class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; ++i) {
            if (vis[i] != -1)
                continue;
            vis[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                auto f = q.front();
                q.pop();
                for (auto& j : graph[f]) {
                    if (vis[j] == -1) {
                        vis[j] = 1 - vis[f];
                        q.push(j);
                    } else if (vis[j] == vis[f])
                        return false;
                }
            }
        }
        return true;
    }
};