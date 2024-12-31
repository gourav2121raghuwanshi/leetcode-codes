class Solution {
    int dp[366];
    int solve(int i, vector<int>& days, vector<int>& costs) {
        if (i >= days.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int day0 = costs[0] + solve(i + 1, days, costs);
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            ++j;
        }
        int day7 = costs[1] + solve(j, days, costs);
        
        while (j < days.size() && days[j] < days[i] + 30) {
            ++j;
        }
        int day30 = costs[2] + solve(j, days, costs);

        return dp[i] = min({day0, day7, day30});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};