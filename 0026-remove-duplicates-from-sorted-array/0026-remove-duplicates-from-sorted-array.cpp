class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(auto&i:nums){
            if(ans.empty() || ans.back()!=i) ans.push_back(i);
        }
        for(int i=0;i<ans.size();++i) nums[i] = ans[i];
        return ans.size();
    }
};