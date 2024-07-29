class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // (a,b)  (c,d)  =>b<c
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };

        sort(pairs.begin(), pairs.end(), comp);

        int ans = 1;
        int prev = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > prev) {
                ++ans;
                prev = pairs[i][1];
            } else {
                continue;
            }
        }
        return ans;
    }
};