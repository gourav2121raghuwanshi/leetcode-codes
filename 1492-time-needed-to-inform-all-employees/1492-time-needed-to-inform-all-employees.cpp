class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        // BFS traversal
        int ans = 0;
        queue<pair<int, int>> q; // {node, cumulative time}
        q.push({headID, 0});

        while (!q.empty()) {
            auto [node, cost] = q.front();
            q.pop();
            ans = max(ans, cost);

            for (int subordinate : adj[node]) {
                q.push({subordinate, cost + informTime[node]});
            }
        }

        return ans;
    }
};
