class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;
        vector<int> curr = intervals[0];
        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < curr[1]) {
                ++ans;
            } else {
                curr = intervals[i];
            }
        }
        return ans;
    }
};