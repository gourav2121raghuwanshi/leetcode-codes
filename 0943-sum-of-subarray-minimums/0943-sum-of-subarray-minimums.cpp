class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        stack<int> st;
        vector<int> prevSmall(n), nextSmall(n);

        // Calculate previous smaller elements
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear the stack for reuse
        while (!st.empty()) st.pop();

        // Calculate next smaller elements
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }


        // Calculate the result
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long next = nextSmall[i] - i;
            long long prev = i - prevSmall[i];
            // cout<<next<<" ,,"<<prev<<endl;
            ans = (ans + arr[i] * next % mod * prev % mod) % mod;
        }

        return ans;
    }
};
