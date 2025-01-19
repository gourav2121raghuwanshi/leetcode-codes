class Solution {
    using p = pair<int, pair<int, int>>;
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int n = hm.size();
        if (n == 0) return 0; // Edge case: empty height map
        int m = hm[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<p, vector<p>, greater<p>> pq;

        // Add all boundary cells to the priority queue and mark them as visited
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({hm[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;
        int row[] = {0, 0, 1, -1};
        int col[] = {1, -1, 0, 0};

        // Process the priority queue
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int ht = front.first;
            int r = front.second.first;
            int c = front.second.second;

            // Visit all 4 neighbors
            for (int k = 0; k < 4; ++k) {
                int dr = row[k] + r;
                int dc = col[k] + c;

                // Check bounds and visited status
                if (dr < 0 || dc < 0 || dr >= n || dc >= m || vis[dr][dc]) continue;

                // Calculate water trapped and update answer
                ans += max(0, ht - hm[dr][dc]);

                // Add the neighboring cell to the priority queue with updated height
                pq.push({max(ht, hm[dr][dc]), {dr, dc}});
                vis[dr][dc] = true; // Mark as visited
            }
        }
        return ans;
    }
};
