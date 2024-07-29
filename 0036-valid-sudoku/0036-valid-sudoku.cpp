class Solution {

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, bool> mp;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                string row = to_string(i) + "row" + board[i][j];
                string col = to_string(j) + "col" + board[i][j];
                string by3 =
                    to_string(i / 3) + ":" + to_string(j / 3) + board[i][j];

                if (mp.count(row) || mp.count(row) || mp.count(by3))
                    return false;

                mp[row] = true;
                if (mp.count(col))
                    return false;

                mp[col] = true;
                if (mp.count(by3))
                    return false;
                mp[by3] = true;
            }
        }
        return true;
    }
};