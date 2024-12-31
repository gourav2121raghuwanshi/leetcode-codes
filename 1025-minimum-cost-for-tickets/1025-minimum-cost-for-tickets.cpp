class Solution {
    int dp[366];
    int solve(int i, vector<int>& days, vector<int>& costs) {
        if (i >= days.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        int day1 = costs[0] + solve(i + 1, days, costs);
        int day7 = costs[1];
        int j = i;
        int cango = days[i] + 7;
        while (j < days.size() && days[j] < cango)
            ++j;
        day7 += solve(j, days, costs);

        int day30 = costs[2];
        j = i;
        cango = days[i] + 30;
        while (j < days.size() && days[j] < cango)
            ++j;
        day30 += solve(j, days, costs);
        return dp[i] = min({day1, day7, day30});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0, days, costs);
    }
};