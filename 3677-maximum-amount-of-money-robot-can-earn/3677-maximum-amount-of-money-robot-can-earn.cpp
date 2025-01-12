class Solution {
int n,m;
int dp[501][501][3];
int solve(int i,int j,int k,vector<vector<int>>& coins){
    if(i==n-1 && j==m-1) {
        if(coins[i][j]>=0) return coins[i][j];
        else if(k>0) return 0;
        else return coins[i][j];
    }
    if(i>=n || j>=m) return -1e9;

    if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
    int take=-1e9;
    int ntake=-1e9;
    int useK=-1e9;
    if(coins[i][j]>=0){
        take=coins[i][j]+max(solve(i+1,j,k,coins),solve(i,j+1,k,coins));
    }else{
        ntake=coins[i][j]+max(solve(i+1,j,k,coins),solve(i,j+1,k,coins));
        if(k>0){
            useK=max(solve(i+1,j,k-1,coins),solve(i,j+1,k-1,coins));
        }
    }
    return dp[i][j][k] = max({take,useK,ntake});
    
}
public:
    int maximumAmount(vector<vector<int>>& coins) {
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        n=coins.size();
        m=coins[0].size();
        return solve(0,0,2,coins);
    }
};