class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int c=1;
        for(int j=1;j<nums.size();++j){
            if(nums[j]==nums[j-1]) ++c;
            else c=1;
            if(c<=2){
                nums[i++]=nums[j];
            }
        }
        return i;

    }
};