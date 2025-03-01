class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n-1;++i){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
                // if(nums[i]!=0) ans.push_back(nums[i]);
            }
        }
        for(auto&i:nums){
            if(i!=0) ans.push_back(i);
        }
        for(auto&i:nums){
            if(i==0) ans.push_back(i);
        }
      
    //   while(ans.size()<nums.size())
        return ans;
        
    }
};