class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> dist;
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            vector<int> curr = routes[i];
            for (auto& j : curr) {
                dist[j] = 1e9;
                adj[j].push_back(i);
            }
        }
        dist[source] = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>,
        //                greater<pair<int, int>>>
        //     q;
        queue<pair<int, int>> q;
        unordered_set<int>visitedBuses;
        q.push({0, source});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int cost = front.first;
            int node = front.second;
            if (node == target)
                return cost;
            vector<int>& routeIdxs = adj[node];
            for (auto& k : routeIdxs) {
                if(visitedBuses.count(k)) continue;
                visitedBuses.insert(k);
                for (auto& j : routes[k]) {
                    if (j == node)
                        continue;
                    if (dist[j] > cost + 1) {
                        dist[j] = 1 + cost;
                        q.push({dist[j], j});
                    }
                }
            }
        }
        return -1;
        return dist[target] == 1e9 ? -1 : dist[target];
    }
};