class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});
        }

        vector<double> dist(n, INT_MIN);
        dist[start_node] = 0;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int node = front.second;
            double prob = front.first;
            for (auto& j : adj[node]) {
                if (dist[j.first] < prob * 1.0 * j.second) {
                    dist[j.first] = prob * 1.0 * j.second;
                    pq.push({dist[j.first], j.first});
                }
            }
        }
        return dist[end_node] == INT_MIN ? 0 : dist[end_node];
    }
};