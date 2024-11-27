class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // logic : only same and ooposite row to current row will form answer with it 
        // so check accordingly 
        int ans = 0;
        unordered_map<string, int> mp;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            string a, b;
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j]) {
                    a.push_back('1');
                    b.push_back('0');
                } else
                    a.push_back('0'), b.push_back('1');
            }
            ans=max(ans,mp[a]+1);
            ans=max(ans,mp[b]+1);
            ++mp[a],++mp[b];
        }
        return ans;
    }
};