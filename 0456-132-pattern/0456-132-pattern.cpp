class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = -1e9;
        int third= -1e9;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;--i){
            if(third>nums[i]) return true;
            
                while(!st.empty() && st.top()<nums[i]){
                    third=(st.top());
                    st.pop();
                }
                
            st.push(nums[i]);
        }
        return false;
    }
};