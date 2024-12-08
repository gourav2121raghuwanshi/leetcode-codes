class Solution {
    int dp[(int)1e5 + 1][2];

    vector<int> nextIdx;

    int solve(int i, vector<vector<int>>& events, int cnt) {
        if (i >= events.size() || cnt >= 2)
            return 0;
        if (dp[i][cnt] != -1)
            return dp[i][cnt];
        int nt = solve(i + 1, events, cnt);
        int take = 0;

        take += events[i][2] + solve(nextIdx[i], events, cnt + 1);

        return dp[i][cnt] = max(take, nt);
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp,-1,sizeof(dp));
        sort(events.begin(), events.end());

        for (int i = 0; i < events.size(); i++) {
            int nidx = lower_bound(events.begin() + i + 1, events.end(),
                                   vector<int>{events[i][1] + 1, 0, 0}) -
                       events.begin();

            if (nidx < events.size())
                nextIdx.push_back(nidx);
            else
                nextIdx.push_back(events.size());
        }

        return solve(0, events, 0);
    }
};