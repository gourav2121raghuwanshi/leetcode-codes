class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {
        vector<pair<int, int>> dir = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};
        set<pair<int, int>> st;
        for (auto& i : queens) {
            st.insert({i[0], i[1]});
        }
        vector<vector<int>> ans;
        // vector<bool>vis(8,false);
        for (int i = 0; i < 8; i++) {
            int dr = king[0];
            int dc = king[1];
            while (dr < 8 && dc < 8 && dr >= 0 && dc >= 0) {
                dr += dir[i].first;
                dc += dir[i].second;
                if (st.count({dr, dc})) {
                    ans.push_back({dr, dc});
                    break;
                }
            }
        }
        return ans;
    }
};