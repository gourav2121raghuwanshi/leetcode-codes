class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<pair<int, int>> dir = {
            {-1, 0},  // Up
            {1, 0},   // Down
            {0, -1},  // Left
            {0, 1},   // Right
            {-1, -1}, // Up-Left
            {-1, 1},  // Up-Right
            {1, -1},  // Down-Left
            {1, 1}    // Down-Right
        };
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({1, 0, 0});
        vector<int> dist(n * n + 1, 1e9);
        dist[0] = 1;
        while (!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            if (t[1] == n - 1 && t[2] == n - 1)
                return t[0];

            for (auto& k : dir) {
                int dx = t[1] + k.first;
                int dy = t[2] + k.second;
                if (dx >= 0 && dy >= 0 && dx < n && dy < n &&
                    dist[dx * n + dy] > 1 + t[0] && grid[dx][dy]==0) {
                    dist[dx * n + dy] = 1 + t[0];
                    pq.push({dist[dx * n + dy], dx, dy});
                }
            }
        }
        return -1;
    }
};