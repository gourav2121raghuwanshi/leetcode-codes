class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int req=t-nums[i];
            if(mp.count(req)) return {mp[req],i};
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};