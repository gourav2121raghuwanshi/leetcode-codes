class Solution {
    int n, m;

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        n = boxGrid.size();
        m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = m - 2; j >= 0; --j) {
                if (boxGrid[i][j] == '#') {
                    int temp = j;
                    for (int k = j + 1; k < m; ++k) {
                        if (boxGrid[i][k] == '*' || boxGrid[i][k] == '#')
                            break;
                        if (boxGrid[i][k] == '.') {
                            boxGrid[i][temp] = '.';
                            boxGrid[i][k] = '#';
                            temp = k;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[j][n - 1 - i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};