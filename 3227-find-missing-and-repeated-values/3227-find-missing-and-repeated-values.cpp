class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int range = n * n;
        vector<int> m(range+1, 0);
        vector<int> ans;
        int a, b;
        for (const auto& i : grid) {
            for (auto& j : i) {
                ++m[j];
            }
        }
        for (int i = 1; i <= range; ++i) {
            if (m[i] == 0)
                a = i;
            if (m[i] == 2)
                b = i;
        }
        return {b, a};
    }
};