class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        // east or west : increase by 1.
        vector<vector<int>> ans;
        int c = 0;
        int i = rStart;
        int j = cStart;

        int dir = 0;
        // directions to follow :  e  , s, w , n
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int number_of_elements_to_take = 0;
        while (ans.size() < rows * cols) {

            if (dir == 0 || dir == 2)
                ++number_of_elements_to_take;
                
            for (int col = 0; col < number_of_elements_to_take; ++col) {
                if (i >= 0 && j >= 0 && i < rows && j < cols) {
                    ans.push_back({i, j});
                }
                i += directions[dir].first;
                j += directions[dir].second;
            }

            dir = (dir + 1) % 4;
        }
        return ans;
    }
};