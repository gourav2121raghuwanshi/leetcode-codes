class Solution {
    bool valid(int mid,vector<int>& arr, int k){
        int i=0;
        int c=0;
        while(i<arr.size()){
            if(arr[i]<=mid){
                ++c;
                i+=2;
            }else i++;
        }
        return c>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
       int l=0;
       int r=*max_element(nums.begin(),nums.end());
       int ans=-1;
       while(l<=r){
        int mid=(l+(r-l)/2);
        if(valid(mid,nums,k)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
       }
       return ans;
    }
};