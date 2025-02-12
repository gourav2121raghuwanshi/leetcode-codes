class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto i:nums){
            int sum=0;
            int temp=i;
            while(i>0){
                sum+=i%10;
                i/=10;
            }
            
            if(mp.count(sum)){
                ans=max(ans,mp[sum]+temp);
                mp[sum]=max(mp[sum],temp);
            }else mp[sum]=temp;
        }
        return ans==0?-1:ans;
    }
};