class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return n;
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j] && j==i+1){
                ++i,++j;
            }
            else if(nums[i]!=nums[j] && j!=i+1){
                nums[i+1]=nums[j];
                i++;
            }
            else if(nums[i]==nums[j]){
                ++j;
            }
        }
        // for(auto&i:nums) cout<<i<<" ";
        // cout<<endl;
        // cout<<i;
        
        return i+1;
    }
};