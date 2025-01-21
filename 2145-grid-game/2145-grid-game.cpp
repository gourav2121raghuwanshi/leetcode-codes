class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long total_sum = 0;
        int m = grid[0].size();
        vector<long long> pref1(m);
        vector<long long> pref2(m);
        for (int i = 0; i < 2; i++) {
            long long s = 0;
            for (int j = 0; j < m; j++) {
                s += grid[i][j];
                total_sum += grid[i][j];
                if (i == 0)
                    pref1[j] = s;
                else
                    pref2[j] = s;
            }
        }
        // long long taken_out = 0;
        int switchi = 0;
        long long given=LLONG_MAX;
        
        for (int i = 0; i < m; i++) {
            long long first_line =pref1[m-1]-(pref1[i]);
            long long second_line=(i-1>=0?pref2[i-1]:0);
            
            if (given > max(first_line , second_line)) {
                given = max(first_line , second_line);
                switchi=i;
            }
        }

        return given;
    }
};