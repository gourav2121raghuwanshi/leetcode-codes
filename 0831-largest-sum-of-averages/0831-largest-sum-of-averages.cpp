class Solution {
    double dp[101][101];
    double solve(int i,vector<int>& nums, int k){
        if(k<0 || i>=nums.size()) return 0;
        if(k==0) return -1e9;
        double sum=0;
        double ans=0;
        if(dp[i][k]!=0) return dp[i][k];
        for(int idx=i;idx<nums.size();++idx){
            sum+=nums[idx];
            int len=idx-i+1;
            ans=max(ans,sum/len+solve(idx+1,nums,k-1));
        }
        return dp[i][k] = ans;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp,0,sizeof(dp));
        return solve(0,nums,k);
    }
};