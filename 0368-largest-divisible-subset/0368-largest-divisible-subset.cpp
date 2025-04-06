class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>last(n,-1);
        int idx=-1;
        int ans=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j]){
                        last[i]=j;
                    dp[i]=max(dp[i],1+dp[j]);}
                }
            }
            if(ans<dp[i]){
                idx=i;
            ans=max(ans,dp[i]);}
        }
        if(idx==-1)
        return {nums[0]};

        vector<int>v;
        while(ans--){
            v.push_back(nums[idx]);
            idx=last[idx];
        }
        return v;
    }
};