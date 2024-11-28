class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l=0;
        long long ans=0;
        long long sum=0;
        for(int r=0;r<nums.size();++r){
            ++mp[nums[r]];
            sum+=nums[r];
            while(mp.size()<r-l+1 || mp.size()>k){
                --mp[nums[l]];
                sum-=nums[l];
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                ++l;
            }
            if(mp.size()==k) ans=max(ans,sum);
        }
        return ans;
    }
};