class Solution {
    // maximizing first robot will not work , try minimizing the second robot directly 
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row_one_total_sum = 0;
        int m = grid[0].size();
        for (int j = 0; j < m; ++j) {
            row_one_total_sum += grid[0][j];
        }

        long long given = LLONG_MAX;
        long long row_two_sum = 0;
        long long row_one_curr_sum=0;
        for (int i = 0; i < m; ++i) {
            row_one_curr_sum += grid[0][i];
            long long first_line = row_one_total_sum - row_one_curr_sum;
            long long second_line = row_two_sum;

            long long curr_given=max(first_line, second_line);
            if (given > curr_given) {
                given = curr_given;
            }
            row_two_sum += grid[1][i];
        }

        return given;
    }
};