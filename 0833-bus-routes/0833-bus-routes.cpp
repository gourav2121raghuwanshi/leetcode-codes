class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> BusIndexesofCurrentStop;
        int n = routes.size();

        for (int i = 0; i < n; ++i) {
            vector<int> curr = routes[i];
            for (auto& j : curr) {
                BusIndexesofCurrentStop[j].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visitedBuses;
        q.push({0, source});

        while (!q.empty()) {
            auto [cost, node] = q.front();
            q.pop();
            if (node == target) {
                return cost;
            }

            vector<int>& routeIdxs = BusIndexesofCurrentStop[node];
            
            for (auto& k : routeIdxs) {
                if (visitedBuses.count(k))
                    continue;
                visitedBuses.insert(k);
                for (auto& j : routes[k]) {
                    if (j == node)
                        continue;
                    q.push({1 + cost, j});
                }
            }
        }
        return -1;
    }
};