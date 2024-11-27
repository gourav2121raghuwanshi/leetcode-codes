class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Total cells
        int total = n * m;

        // Create a set for walls and guards
        set<pair<int, int>> st, guardSet;
        for (auto& i : walls) {
            st.insert({i[0], i[1]});
        }
        for (auto& i : guards) {
            guardSet.insert({i[0], i[1]});
        }

        // Mark visible cells
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];

            // Right
            for (int j = y + 1; j < m && !st.count({x, j}) && !guardSet.count({x, j}); ++j) {
                vis[x][j] = true;
            }

            // Left
            for (int j = y - 1; j >= 0 && !st.count({x, j}) && !guardSet.count({x, j}); --j) {
                vis[x][j] = true;
            }

            // Down
            for (int i = x + 1; i < n && !st.count({i, y}) && !guardSet.count({i, y}); ++i) {
                vis[i][y] = true;
            }

            // Up
            for (int i = x - 1; i >= 0 && !st.count({i, y}) && !guardSet.count({i, y}); --i) {
                vis[i][y] = true;
            }
        }

      
       int guarded = walls.size() + guards.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j]) {
                    ++guarded;
                }
            }
        }

        return total - guarded;
    }
};
