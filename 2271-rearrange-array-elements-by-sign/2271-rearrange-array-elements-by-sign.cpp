class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int m=nums.size();
        vector<int>ans(m);
        int p=0;
        int n=1;
        for(auto&i:nums){
            if(i<0){
                ans[n]=i;
                n+=2;
            }else{
                ans[p]=i;
                p+=2;
            }
        }
        return ans;
    }
};