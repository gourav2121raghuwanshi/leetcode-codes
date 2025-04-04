class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto&i:nums){
            if(i&1) i=1;
            else i=0;
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(auto&i:nums){
            sum+=i;
            ans+=mp[sum-k];
            ++mp[sum];
        }
        return ans;
    }
};