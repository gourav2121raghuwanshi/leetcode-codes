class Solution {
    int solve(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(-1);
        vector<int> nextSmall(n);
        for (int i = n - 1; i >= 0; --i) {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
                st.pop();
            nextSmall[i] = st.top();
            st.push(i);
        }
        while (st.top() != -1)
            st.pop();
        vector<int> prevSmall(n);
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
                st.pop();

            prevSmall[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {

            if (nextSmall[i] == -1)
                nextSmall[i] = n;
            ans = max(ans, heights[i] * (nextSmall[i] - prevSmall[i] - 1));
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    ++heights[j];
                } else
                    heights[j] = 0;
            }
            ans = max(ans, solve(heights));
        }
        return ans;
    }
};