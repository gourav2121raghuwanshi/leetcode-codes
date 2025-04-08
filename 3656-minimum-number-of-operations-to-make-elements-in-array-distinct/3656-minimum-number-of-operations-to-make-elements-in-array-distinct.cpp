class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums) ++mp[i];
        if(mp.size()==nums.size()) return 0;
        int i=0;
        int c=0;
        int ans=0;
        while(mp.size()<nums.size()-c){
            int cnt=3;
            ++ans;
            while(cnt-- && i<nums.size()){
                --mp[nums[i]];
                ++c;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                ++i;
            }
            // cout<<mp.size()<<" - "<<nums.size()-c<<endl;
            
        }
        return ans;
    }
};