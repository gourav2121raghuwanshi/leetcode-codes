class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int ans = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (digits[i] != 0) {
                        int num1 = digits[i] * 100 + digits[j] * 10 + digits[k];
                        int num5 = digits[i] * 100 + digits[k] * 10 + digits[j];
                        if (num1 % 2 == 0)
                            st.insert(num1);
                        if (num5 % 2 == 0)
                            st.insert(num5);
                    }
                    if (digits[j] != 0) {
                        int num2 = digits[j] * 100 + digits[i] * 10 + digits[k];
                        int num6 = digits[j] * 100 + digits[k] * 10 + digits[i];
                        if (num2 % 2 == 0)
                            st.insert(num2);
                        if (num6 % 2 == 0)
                            st.insert(num6);
                    }
                    if (digits[k] != 0) {
                        int num3 = digits[k] * 100 + digits[j] * 10 + digits[i];
                        int num4 = digits[k] * 100 + digits[i] * 10 + digits[j];

                        if (num3 % 2 == 0)
                            st.insert(num3);
                        if (num4 % 2 == 0)
                            st.insert(num4);
                    }

                    // if(num5%2==0) st.insert(num5);
                }
            }
        }
        for (auto i : st)
            cout << i << ' ';
        return st.size();
    }
};