class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
         vector<int> dp(n, 1);
        vector<int>lastIdx(n,-1);
        int idx=0;
        int maxlen=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                   if(dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                    lastIdx[i]=j;
                   }
                }
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
                idx=i;
            }
        }
        
        while(maxlen--){
            ans.push_back(nums[idx]);
            idx=lastIdx[idx];
        }   
return ans;
    }
};