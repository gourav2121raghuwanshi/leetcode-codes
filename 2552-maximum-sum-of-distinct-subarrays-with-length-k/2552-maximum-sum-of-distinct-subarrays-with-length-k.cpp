class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int s=0;
        long long ans=0;
        long long sum=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;++i){
            ++mp[nums[i]];
            sum+=nums[i];
            while(mp[nums[i]]>1 || i-s+1>k){
                sum-=nums[s];
                --mp[nums[s]];
                ++s;
            }
            if(i-s+1>=k) ans=max(ans,sum);
        }
        return ans;
    }
};