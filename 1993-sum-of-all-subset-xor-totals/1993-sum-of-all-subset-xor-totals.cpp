class Solution {
    int dp[13][50];
    int solve(int i,int xo,vector<int>& nums){
        if(i>=nums.size()){
            return xo;
        }
        if(dp[i][xo]!=-1) return dp[i][xo];
        int take=solve(i+1,xo^nums[i],nums);
        int ntake=solve(i+1,xo,nums);
        return dp[i][xo] =  take+ntake;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums);
   
    }
};