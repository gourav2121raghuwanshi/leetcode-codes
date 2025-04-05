class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        st.push(-1);
        int n = nums2.size();

        for (int i = n - 1; i >= 0; --i) {
            while (st.top() != -1 && nums2[st.top()] <= nums2[i]) {
                st.pop();
            }
            if (st.top() != -1)
                mp[nums2[i]] = nums2[st.top()];
            else
                mp[nums2[i]] = -1;
            st.push(i);
        }

        vector<int> ans;
        for (auto& i : nums1) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};