class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n), radj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            radj[edge[1]].push_back({edge[0], edge[2]});
        }

        auto dijkstra = [&](int start, vector<vector<pair<int, int>>>& graph) {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            vector<long long> dist(n, LLONG_MAX);
            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u])
                    continue;

                for (auto& [v, weight] : graph[u]) {
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };

        vector<long long> dist1 = dijkstra(src1, adj);
        vector<long long> dist2 = dijkstra(src2, adj);
        vector<long long> dist3 = dijkstra(dest, radj);

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != LLONG_MAX && dist2[i] != LLONG_MAX && dist3[i] != LLONG_MAX) {
                ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
