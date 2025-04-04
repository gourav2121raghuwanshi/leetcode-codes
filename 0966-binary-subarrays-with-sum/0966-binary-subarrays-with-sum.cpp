class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto&i:nums){
            sum+=i;
            ans+=mp[sum-goal];
            ++mp[sum];
        }
        return ans;
    }
};