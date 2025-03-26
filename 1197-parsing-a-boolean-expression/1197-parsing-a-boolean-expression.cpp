class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (auto& i : expression) {
            if (i == ')') {
                int tc = 0;
                int fc = 0;
                while (st.top() != '(') {
                    if (st.top() == 't')
                        ++tc;
                    else if (st.top() == 'f')
                        ++fc;
                    st.pop();
                }
                st.pop();
                char oprtr = st.top();
                st.pop();
                if (oprtr == '|') {
                    if (tc)
                        st.push('t');
                    else
                        st.push('f');
                } else if (oprtr == '&') {
                    if (fc)
                        st.push('f');
                    else
                        st.push('t');
                } else if (oprtr == '!') {
                    if (tc)
                        st.push('f');
                    else
                        st.push('t');
                }
            } else {
                st.push(i);
            }
        }
        return st.top() == 't' ? true : false;
    }
};