class Solution {
    int dp[1001][1005];
 
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                int d=nums[i]-nums[j]+501;
                dp[i][d]= dp[j][d]>0?dp[j][d]+1:2;
                //  max(dp[i][d],1+);
                ans=max(ans,dp[i][d]);
            }
        }

        return ans;
    }
};