class Solution {
    // convert matrix as below :
    // now : 0-> island
    //       1-> water
    // count number of islands
    // : (forward slash) / = [0 0 1
    //                        0 1 0
    // ]                      1 0 0
    // : (backward slash) \\ = [    1 0 0
    //                              0 1 0
    //                              0 0 1
    // ]
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n * 3, vector<int>(m * 3, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == ' ') {
                } else if (grid[i][j] == '/') {
                    mat[i * 3][j * 3 + 2] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3] = 1;
                } else {
                    mat[i * 3][j * 3] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3 + 2] = 1;
                    // ++j;
                }
            }
        }
        int ans = 0;
        int row[] = {0, 0, 1, -1};
        int col[] = {1, -1, 0, 0};
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < m * 3; ++j) {
                if (mat[i][j] == 0) {
                    ++ans;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    mat[i][j] = 1;
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int dr = r + row[k];
                            int dc = c + col[k];
                            if (dr >= 0 && dc >= 0 && dr < n * 3 &&
                                dc < m * 3 && mat[dr][dc] == 0) {
                                mat[dr][dc] = 1;
                                q.push({dr, dc});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};