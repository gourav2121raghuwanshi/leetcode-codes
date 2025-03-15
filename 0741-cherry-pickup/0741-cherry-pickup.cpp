class Solution {
    int n;
    int dp[51][51][51][51];
    int solve(int ar, int ac, int br, int bc, vector<vector<int>>& grid) {
        if (ar >= n || ac >= n || br >= n || bc >= n || grid[ar][ac] == -1 ||
            grid[br][bc] == -1)
            return -1e8;

        // If both reach the bottom-right corner
        if (ar == n - 1 && ac == n - 1)
            return grid[ar][ac];

        // Check memoization
        if (dp[ar][ac][br][bc] != -1)
            return dp[ar][ac][br][bc];

        int cherries = (ar == br && ac == bc) ? grid[ar][ac]
                                              : (grid[ar][ac] + grid[br][bc]);

        int val1 = grid[ar][ac];
        int val2 = grid[br][bc];
        grid[ar][ac] = 0;
        grid[br][bc] = 0;

        int ans = max({
            solve(ar + 1, ac, br + 1, bc, grid), // Both move down
            solve(ar + 1, ac, br, bc + 1,
                  grid), // ar moves down, br moves right
            solve(ar, ac + 1, br + 1, bc,
                  grid),                        // ar moves right, br moves down
            solve(ar, ac + 1, br, bc + 1, grid) // Both move right
        });

        grid[ar][ac] = val1;
        grid[br][bc] = val2;

        return dp[ar][ac][br][bc] = ans + cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int result = solve(0, 0, 0, 0, grid);
        return max(0, result);
    }
};
