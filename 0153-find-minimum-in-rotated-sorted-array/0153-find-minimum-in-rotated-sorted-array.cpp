class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[n-1]>nums[0]) return nums[0];

        int s=0;
        int e=n-1;
        int ans=nums[0];
        while(s<e){
            int mid=(s+e)/2;
            if(nums[0]<=nums[mid]){
                s=mid+1;
            }else e=mid;
        }
        return nums[s];
    }
};