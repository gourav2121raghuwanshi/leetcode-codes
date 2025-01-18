class Solution {
    int n, m;
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= n || j >= m || grid[i][j] != 1)
            return false;
        if (i == n - 1 && j == m - 1)
            return true;
        grid[i][j] = 0;
        if (dfs(i + 1, j, grid))
            return true;
        if (dfs(i, j + 1, grid))
            return true;

        return false;
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if ((n == 1 && m == 2) || (n == 1 && m == 1) || (n == 2 && m == 1)) {
            return false;
        }

        if (dfs(0, 0, grid) == false)
            return 1;
        grid[0][0]=1;
         if (dfs(0, 0, grid) == false)
            return 1;
        return false;
    }
};