class Solution {
    int search(int s,int e,vector<int>& nums,int t){
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==t) return mid;
            else if(nums[mid]>t) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        if(n==1){
            return nums[0]==t?0:-1;
        }

        if(nums[0]<nums[n-1]){
            return search(0,n-1,nums,t);
        }
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=(s+e)/2;
            if(nums[0]<=nums[mid]){
                s=mid+1;
            }else e=mid;
        }
        cout<<s<<endl;
        int ans1=search(0,s-1,nums,t);
        if(ans1!=-1) return ans1;
        ans1=search(s,n-1,nums,t);
        return ans1;
    }

};