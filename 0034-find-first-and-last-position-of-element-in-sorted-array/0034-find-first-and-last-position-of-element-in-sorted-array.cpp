class Solution {
    int s(int l,int r,vector<int>& nums, int t){
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==t){
                ans=mid;
                r=mid-1;
            }else if(nums[mid]>t){
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
    int e(int l,int r,vector<int>& nums, int t){
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==t){
                ans=mid;
                l=mid+1;
            }else if(nums[mid]>t){
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int t) {
    //    vector<int>ans;
       int n=nums.size()-1;
        int start=s(0,n,nums,t);
        int end=e(0,n,nums,t);
       return {start,end}; 
    }
};