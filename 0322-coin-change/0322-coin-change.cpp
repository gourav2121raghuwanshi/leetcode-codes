class Solution {
    int dp[13][10001];
    int solve(vector<int>& coins, int amount,int i){
        if(amount==0) return 0;
        if(i>=coins.size() || amount<0) return 1e7;
        if(dp[i][amount]!=-1) return dp[i][amount];
        return dp[i][amount] = min(solve(coins,amount,i+1),1+solve(coins,amount-coins[i],i));
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans= solve(coins,amount,0);
        return ans==1e7?-1:ans;
    }
};