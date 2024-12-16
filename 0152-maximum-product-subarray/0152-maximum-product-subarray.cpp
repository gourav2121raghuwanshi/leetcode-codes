class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long suff=1;
        long long pref=1;
        long long ans=-1e9;
        for(int i=0;i<nums.size();++i){
                suff*=nums[nums.size()-1-i];
                pref*=nums[i];
                ans=max(ans,max(suff,pref));
                if(suff==0) suff=1;
                if(pref==0) pref=1;
        }
        return ans;
    }
};