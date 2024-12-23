class Solution {
    int dp[501];
    int solve(int i,vector<int>& arr, int k){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0;
        int currmax=0;
        for(int j=i;j<min((int)arr.size(),i+k);++j){
            currmax=max(currmax,arr[j]);
            maxi=max(maxi,currmax*(j-i+1)+solve(j+1,arr,k));
        }
        return dp[i] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,arr,k);
    }
};