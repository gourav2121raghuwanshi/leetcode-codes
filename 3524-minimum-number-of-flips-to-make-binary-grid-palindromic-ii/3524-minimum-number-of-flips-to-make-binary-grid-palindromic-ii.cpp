class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                int x = grid[i][j];
                x += grid[i][m - j - 1];
                x += grid[n - i - 1][j];
                x += grid[n - i - 1][m - j - 1];
                ans += min(4 - x, x);
            }
        }
        int c = 0;
        int OneZeroPairCount = 0;
        if (n & 1) {
            for (int j = 0; j < m / 2; ++j) {
                if (grid[n / 2][j] != grid[n / 2][m - j - 1]) {
                    ++OneZeroPairCount;
                    ++ans;
                } else if (grid[n / 2][j] == grid[n / 2][m - j - 1] &&
                           grid[n / 2][j]) {
                    ++c;
                }
            }
        }

        if (m & 1) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[j][m / 2] != grid[n - j - 1][m / 2]) {
                    ++OneZeroPairCount;
                    ++ans;
                } else if (grid[j][m / 2] == grid[n - j - 1][m / 2] &&
                           grid[j][m / 2]) {
                    ++c;
                }
            }
        }
        // total number of one has to be multiple of 4
        if (c % 2 == 1 && OneZeroPairCount == 0)
            ans += 2;

        if ((n % 2 == 1 && m % 2 == 1) && grid[n / 2][m / 2])
            ++ans;
        return ans;
    }
};