class Solution {
    int n, m;
    bool valid(int r,int c,char ch,vector<vector<char>>& board){

        for(int i=0;i<9;++i){
            if(board[r][i]==ch || board[i][c]==ch) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (valid(i, j, ch, board)) {
                            board[i][j] = ch;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        solve(board);
    }
};