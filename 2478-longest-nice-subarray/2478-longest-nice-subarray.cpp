class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int setBits=0;
        int s=0;
        int ans=0;

        for(int e=0;e<nums.size();++e){
            for(int j=0;j<32;++j){
                if(nums[e]&(1<<j)){
                    if((setBits&(1<<j))){
                        while(s<e && (setBits&(1<<j))){
                            setBits-=nums[s++];
                        }
                    }
                }
            }
            setBits+=nums[e];
            ans=max(ans,e-s+1);
        }
        return ans;
    }
};