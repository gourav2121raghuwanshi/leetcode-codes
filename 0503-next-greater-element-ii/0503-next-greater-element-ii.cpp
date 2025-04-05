class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        // for(int i=0;i<n-1;++i){
        //     nums.push_back(nums[i]);
        // }
        
        vector<int>ans(n);
        stack<int>st;
        // for(int i=2*n-2;i>=n;--i){
        //     st.push(i);
        // }
        for(int i=n-1;i>=0;--i){
            st.push(nums[i]);
        }
        // [1,2,3,4,3,1,2,3,4]
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]= (st.top());
            st.push(nums[i]);
        }

        return ans;
    }
};