class Solution {
    bool valid(int a,int b,int c){
        return a+b>c && b+c>a && a+c>b;
    }
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=n-1;i>=0;--i){
            int s=0;
            int e=i-1;
            while(s<e){
                if(nums[s]+nums[e]>nums[i]){
                    ans+=e-s;
                    --e;
                }else ++s;
            }
        }
        return ans;
    }
};