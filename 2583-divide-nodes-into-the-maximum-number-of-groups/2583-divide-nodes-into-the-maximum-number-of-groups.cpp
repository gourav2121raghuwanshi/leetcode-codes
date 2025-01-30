class Solution {
    unordered_map<int, vector<int>> adj;

    void dfs(int node, unordered_set<int>& comp, vector<int>& vis) {
        if (comp.count(node)) return;
        comp.insert(node);
        vis[node] = 1; // Mark as visited
        for (auto& i : adj[node]) {
            dfs(i, comp, vis);
        }
    }

    int m;

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        m = n;
        for (auto& i : edges) {
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = 0;
        vector<int> vis(n + 1, -1);

        for (int i = 1; i <= n; ++i) {
            if (vis[i] == -1) {
                unordered_set<int> comp;
                dfs(i, comp, vis);

                int maxDepth = -1;
                for (auto& i : comp) {
                    vector<int> dist(n + 1, -1);  // Create a fresh distance array
                    maxDepth = max(maxDepth, bfs(i, dist));
                }
                if (maxDepth == -1) return -1;
                ans += maxDepth;
            }
        }
        return ans;
    }

    int bfs(int node, vector<int>& dist) {
        dist[node] = 1;
        queue<int> q;
        q.push(node);
        int depth = 1;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto& i : adj[front]) {  // Corrected from adj[node] to adj[front]
                if (dist[i] == -1) {
                    dist[i] = dist[front] + 1;
                    depth = max(depth, dist[i]);
                    q.push(i);
                } else if (abs(dist[i] - dist[front]) != 1) {
                    return -1;  // Graph is not bipartite
                }
            }
        }
        return depth;
    }
};
