class Solution {
public:
int isval(vector<int>& nums,long long mid, int k){
    int val=1;
    long long int sum=0;
    int n=nums.size();
    for(int i=0;i<n;++i){
        if(sum+nums[i]<=mid) sum+=nums[i];
        else{
            ++val;
            sum=nums[i];
        }
    }
    return val;
}
    int splitArray(vector<int>& nums, int k) 
    {
        // if(k>nums.size( )) return -1;
        int s=*max_element(nums.begin(),nums.end());
        long long  e=accumulate(nums.begin(),nums.end(),0);
        long long  mid;
        while(s<=e){
               mid=(s+e)/2;
               int stud=isval(nums,mid,k);
               if(stud>k) s=mid+1; 
               else e=mid-1;
        }
        return s;
    }
};