class Solution {
    int dp[101][101][101];
    int solve(int i,int op1, int op2,int k,vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];
        int a=nums[i]+solve(i+1,op1,op2,k,nums);
        int b=1e9;
        if(op1>0){
            b=ceil(nums[i]*1.0/2.0)+solve(i+1,op1-1,op2,k,nums);
            int c=1e9;
            if(op2>0 && ceil(nums[i]*1.0/2.0)>=k){
                c=ceil(nums[i]*1.0/2.0)-k+solve(i+1,op1-1,op2-1,k,nums);
            }
            b=min(b,c);
        }
        int c=1e9;
        if(op2>0 && nums[i]>=k){
            c=nums[i]-k+solve(i+1,op1,op2-1,k,nums);
            int d=1e9;
            if(op1){
                d=ceil((nums[i]-k)*1.0/2.0)+solve(i+1,op1-1,op2-1,k,nums);
            }
            c=min(c,d);
        }
        return dp[i][op1][op2] =  min({a,b,c});

    }
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,op1,op2,k,nums);
    }
};