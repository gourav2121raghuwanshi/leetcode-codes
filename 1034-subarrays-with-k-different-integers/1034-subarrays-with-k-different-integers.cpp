class Solution {
    int solve(vector<int>& nums, int k){ // number of distinct integers in subarry >=k

    int ans=0;
    unordered_map<int,int>mp;
    int s=0;
    for(int e=0;e<nums.size();++e){
        ++mp[nums[e]];
        while(s<=e && mp.size()>k){
            --mp[nums[s]];
            if(mp[nums[s]]==0){
                mp.erase(nums[s]);
            }
            ++s;
        }
        ans+=(e-s+1);
    }
    return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};