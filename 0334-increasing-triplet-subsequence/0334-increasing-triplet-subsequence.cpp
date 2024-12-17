class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int three=INT_MIN;
        int two=INT_MIN;

        int n=nums.size();
        for(int i=n-1;i>=0;--i){
            if(nums[i]<two) return true;
            else if(nums[i]<three){
                two=max(two,nums[i]);
            }else three=nums[i];
        }
        return false;
    }
};