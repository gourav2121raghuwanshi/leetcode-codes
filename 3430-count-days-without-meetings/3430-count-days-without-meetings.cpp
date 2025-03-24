class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        int n=meetings.size();
        sort(meetings.begin(), meetings.end());
        int currEnd = 0;
        for (int i = 0; i < n; ++i) {
            if (meetings[i][0] > currEnd + 1) {
                ans += meetings[i][0] - currEnd - 1;
            }
            currEnd = max(currEnd, meetings[i][1]);
        }
        if (days > currEnd)
            ans += days - currEnd;
        return ans;
    }
};