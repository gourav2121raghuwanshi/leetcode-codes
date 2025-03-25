class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    //  1,2,2,5,6,6   
    // 1,2 2,5 6,6
    // 1,2,3,4 -> 
    int ans=0;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i+=2) ans+=nums[i];
    return ans;
    }
};