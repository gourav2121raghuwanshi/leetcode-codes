class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int c;
        multiset<int> st;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            while (*st.rbegin() - *st.begin() > 2) {
                st.erase(st.find(nums[s]));
                ++s;
            }
            c = (i - s + 1);
            ans = ans + c;
        }
         
        return ans;
    }
};