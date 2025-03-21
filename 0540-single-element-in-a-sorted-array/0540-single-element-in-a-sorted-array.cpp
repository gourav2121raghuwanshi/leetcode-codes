class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int s=1;
        int e=n-2;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            if((mid&1) && nums[mid]==nums[mid-1]){
                s=mid+1;
            }else if((mid%2==0) && nums[mid]==nums[mid+1]) s=mid+1;
            if((mid&1) && nums[mid]==nums[mid+1]){
                e=mid-1;
            }else if((mid%2==0) && nums[mid]==nums[mid-1]) e=mid-1;
        }
        return -1;
    }
};