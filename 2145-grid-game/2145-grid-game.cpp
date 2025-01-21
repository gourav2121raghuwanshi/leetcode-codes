class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row_one_sum = 0;
        int m = grid[0].size();
        for (int j = 0; j < m; j++) {
            row_one_sum += grid[0][j];
        }

        long long given = LLONG_MAX;
        long long row_two_sum = 0;
        long long s=0;
        for (int i = 0; i < m; i++) {
            s += grid[0][i];

            long long first_line = row_one_sum - s;
            long long second_line = row_two_sum;

            if (given > max(first_line, second_line)) {
                given = max(first_line, second_line);
            }
            row_two_sum += grid[1][i];
        }

        return given;
    }
};