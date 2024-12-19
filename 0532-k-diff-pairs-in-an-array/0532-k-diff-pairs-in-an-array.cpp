class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        set<pair<int,int>>st;
        int ans=0;
        for(auto&i:nums){
            int req=i-k;
            int mini=min(i,req);
            int maxi=max(i,req);
            if(mp.count(req) && !st.count({mini,maxi})){
                ans+=mp[req];
                st.insert({mini,maxi});
            }
            mp[i]=1;
        }
        return ans;
    }
};