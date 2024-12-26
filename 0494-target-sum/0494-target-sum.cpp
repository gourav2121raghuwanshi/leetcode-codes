class Solution {
    unordered_map<string,int>mp;
    string key(int a,int b){
        return to_string(a)+":"+to_string(b);
    }
    int solve(int i,int s,vector<int>& nums, int t){
        if(t==s && i==nums.size()) return 1;
        if(i>=nums.size()) return 0;
        string k=key(i,s);
        if(mp.count(k)) return mp[k];
        return mp[k] = solve(i+1,s+nums[i],nums,t)+solve(i+1,s-nums[i],nums,t);
    }
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        return solve(0,0,nums,t);
    }
};