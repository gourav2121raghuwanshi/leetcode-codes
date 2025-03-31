class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                vis[i][0]=true;
                q.push({i, 0});
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                vis[i][m-1]=true;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                vis[0][j]=true;
                q.push({0, j});
            }
            if (board[n - 1][j] == 'O') {
                vis[n-1][j]=true;
                q.push({n - 1, j});
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& k : dir) {
                int dx = x + k.first;
                int dy = y + k.second;
                if (dx >= 0 && dy >= 0 && dx < n && dy < m &&
                    board[dx][dy] == 'O' && !vis[dx][dy]) {
                    
                    q.push({dx, dy});
                    vis[dx][dy]=true;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
        // return board;
    }
};