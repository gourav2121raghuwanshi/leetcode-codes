class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int sum=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            // if(sum%k==0) ++ans;
            int left=sum%k;
            if(left<0) left+=k;
            ans+=mp[left];
            
            ++mp[left];
        }
        return ans;
    }
};