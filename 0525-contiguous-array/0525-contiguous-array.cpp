class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto&i:nums){
            if(i==0) i=-1;
        }
        unordered_map<int,int>mp;
        int s=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            s+=nums[i];
            if(s==0) ans=i+1;
            if(mp.count(s)) ans=max(ans,i-mp[s]);
            else mp[s]=i;
        }
        return ans;
    }
};