class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;

        for(auto&i:st){
            if(i<k) return -1;
            if(i>k) ++ans;
        }

        return ans;
    }
};