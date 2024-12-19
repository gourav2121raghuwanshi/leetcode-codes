class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int cnt=0;
        int ans=0;

        for(int i=0;i<nums.size();++i){
           if(nums[i]!=-1){
            cnt=0;
            int x=i;
            while(nums[x]!=-1){
                ++cnt;
                int temp=nums[x];
                nums[x]=-1;
                x=temp;
            }
            ans=max(ans,cnt);
           }
        }

        return ans;
    }
};