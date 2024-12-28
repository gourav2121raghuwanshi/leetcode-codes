class Solution {
    vector<int>subarray;
    int n;
    int dp[20001][4];
    int helper(int i,int k,int c){
        if(c==0) return 0;
        if(i>=n) return INT_MIN/2;
        if(dp[i][c]!=-1) return dp[i][c];
        int take=subarray[i]+helper(i+k,k,c-1);
        int ntake=helper(i+1,k,c);

        return dp[i][c] = max(take,ntake);
    }
public:
void solve(int i,int k,int c,vector<int>&ans){
    if(i>=n) return ;
    if(c==0) return;
    int take=subarray[i]+helper(i+k,k,c-1);
    int ntake=helper(i+1,k,c);

    if(take>=ntake){
        ans.push_back(i);
        solve(i+k,k,c-1,ans);
    }else solve(i+1,k,c,ans);
}
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>ans;
        n=nums.size();
        int i=0;
        int sum=0;
        for(int j=0;j<n;++j){
            sum+=nums[j];
            if(j-i+1==k){
                subarray.push_back(sum);
                sum-=nums[i++];
            }
        }
        memset(dp,-1,sizeof(dp));
        n=subarray.size();
        solve(0,k,3,ans);
        return ans;
    }
};