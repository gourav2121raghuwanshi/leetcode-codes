class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        vector<int>nge(n,-1);
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(!st.empty())nge[i]=st.top();
            st.push(nums2[i]);
            mp[nums2[i]]=i;
        }   
        vector<int>ans;
        for(auto&i:nums1){
            ans.push_back(nge[mp[i]]);
        }
        return ans;
    }
};