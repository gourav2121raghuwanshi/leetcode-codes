class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       long long ans=0;
       int n=nums.size() ;
       for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                if(nums[i]>0 && nums[j]>0 && nums[k]>0){
                    ans=max(ans,1LL*((nums[i] - nums[j]) *1LL* nums[k]));
                }
            }
        }
       }
       return ans;
    }
};