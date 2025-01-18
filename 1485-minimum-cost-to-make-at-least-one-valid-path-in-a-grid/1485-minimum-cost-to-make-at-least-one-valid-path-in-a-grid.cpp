class Solution {
    using p = pair<int, pair<int, int>>;

public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> price(n, vector<int>(m, 1e9));
        
        price[0][0] = 0; // Set starting cell cost to 0
        
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int x = front.second.first;
            int y = front.second.second;
            int cost = front.first;

            // If the target cell is reached, return the cost
            if (x == n - 1 && y == m - 1)
                return cost;

            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;

                // Check if the next cell is within bounds
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newCost = cost + (grid[x][y] == i + 1 ? 0 : 1);
                    
                    // Update cost if a better path is found
                    if (newCost < price[nx][ny]) {
                        price[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return -1; // If the target cell is not reachable
    }
};
