class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> mp;
        int n = grid.size();
        int m = grid[0].size();

        // Collect elements along diagonals
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        // Sort diagonals
        for (auto& [key, vec] : mp) {
            if (key < 0) { // Bottom-left triangle (including middle diagonal)
                sort(vec.rbegin(), vec.rend()); // Non-increasing order
            } else { // Top-right triangle
                sort(vec.begin(), vec.end()); // Non-decreasing order
            }
        }

        // Place sorted values back into grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return grid;
    }
};
