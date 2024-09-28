class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        unordered_set<int> st;
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        long long ans = 0;  
        int last=1e9;
        for (auto &i : maximumHeight) {
            i=min(last,i);
            while (st.count(i) && i > 0) {
                --i;
            }
            if (i > 0) {
                ans += i;
                st.insert(i);
                last=min(last,i);
            } else {
                return -1;  
                 }
        }
        
        return ans;
    }
};
