class Solution {
public:
    bool isVal(int mid,vector<int> nums){
        int n = nums.size();
        long long extra = 0; 
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] + extra > mid) {
                extra += nums[i] - mid;
            } else {
                extra = 0;
            }
        }

        return nums[0] + extra <= mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int s=0;
        int e=*max_element(nums.begin(),nums.end());
        int maxi=e;
        while(s<=e){          
            int mid=s+(e-s)/2;
            if(isVal(mid,nums)){
                maxi=mid;
                e=mid-1;
            }else s=mid+1;
        }                  
        return maxi;
    }
};