class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(v.empty() || v.back()<nums[i]) v.push_back(nums[i]);
            else {
                int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[idx]=nums[i];
            }
        }

        return v.size();
    }
};