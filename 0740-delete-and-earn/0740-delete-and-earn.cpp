class Solution {
    vector<int>arr;
    vector<int>dp;
    int solve(int i){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(arr[i]+solve(i+2),solve(i+1));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        arr.resize((int)20001,0);
        dp.resize((int)20001,-1);
        for(auto&i:nums){
            arr[i]+=i;
        }
        return solve(1);
    }
};