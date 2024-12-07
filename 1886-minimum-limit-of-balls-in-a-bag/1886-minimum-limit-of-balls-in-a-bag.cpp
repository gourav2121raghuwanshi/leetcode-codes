class Solution {
    bool valid(int mid,vector<int>nums, int maxOperations){
        for(int i=0;i<nums.size();i++){
           if(nums[i]>mid){
            int req= ceil(nums[i]*1.0/mid)-1;
            maxOperations-=req;
            if(maxOperations<0) return false;
           }
         
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        // try out all possible bag sizes
        // now try to reduce all to less equal to mid size
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(valid(mid,nums,maxOperations)){
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
};