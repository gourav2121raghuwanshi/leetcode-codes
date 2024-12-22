class Solution {
    int dp[1001][1005];
    int solve(int i,int d,vector<int>& nums){
        if(i>=nums.size()) return 0;
        int ans=0;
        if(dp[i][d]!=-1){
           return dp[i][d];
        }
        for(int k=i+1;k<nums.size();++k){
            if(nums[k]-nums[i]+501==d){
                  ans = max(ans,1 + solve(k, d, nums));
            }
        }
        return dp[i][d] = ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
       
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int d=nums[j]-nums[i]+501;
                int val=  solve(j,d,nums);
                ans=max(ans,2+val);
            }
        }

        return ans;
    }
};