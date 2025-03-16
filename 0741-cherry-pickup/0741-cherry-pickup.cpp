class Solution {
    // since both moves one step ahead (+1 always)
    // therefore : r1+c1=r2+c2
    // if we know r1,c1,c2 -> then we can get r2
    int n;
    int dp[51][51][51];
    int solve(int r1, int c1, int c2, vector<vector<int>>& grid) {
        int r2 = r1 + c1 - c2; // Compute r2 using the equation

         if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
            return -1e8;

        // If both reach the bottom-right corner
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];

        int cherry = grid[r1][c1];
        if (c1 != c2)
            cherry += grid[r2][c2]; // Avoid double counting

        // Explore all movement options
        int ans = -1e9;
        ans = max(ans, solve(r1 + 1, c1, c2, grid));     // Down, down
        ans = max(ans, solve(r1, c1 + 1, c2 + 1, grid)); // Right, right
        ans = max(ans, solve(r1 + 1, c1, c2 + 1, grid)); // Down, right
        ans = max(ans, solve(r1, c1 + 1, c2, grid));     // Right, down

        return dp[r1][c1][c2] = ans + cherry;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, grid);
        return ans < 0 ? 0 : ans;
    }
};
