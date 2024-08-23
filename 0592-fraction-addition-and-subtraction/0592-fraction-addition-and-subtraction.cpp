class Solution {
public:
    string fractionAddition(string s) {
        int i = 0;
        int n = s.size();
        stack<int> st;
        while (i < n) {
            int f = 1;
            if (s[i] == '-') {
                f = -1;
                ++i;
            } else if (s[i] == '+')
                ++i;
            int a = 0;
            while (i < n && isdigit(s[i])) {
                a = a * 10 + (s[i] - '0');
                ++i;
            }
            a *= f;
            if (i < n && s[i] == '/')
                ++i;

            int b = 0;
            while (i < n && isdigit(s[i])) {
                b = b * 10 + (s[i] - '0');
                ++i;
            }

            if (st.empty() && i == n) {
                return to_string(a) + "/" + to_string(b);
            } else if (st.empty()) {
                int c = 0;
                int plus = 1;
                if (i < n && s[i] == '-') {
                    plus = -1;
                }
                ++i;
                while (i < n && isdigit(s[i])) {
                    c = c * 10 + (s[i] - '0');
                    ++i;
                }
                if (i < n && s[i] == '/')
                    ++i;

                int d = 0;
                while (i < n && isdigit(s[i])) {
                    d = d * 10 + (s[i] - '0');
                    ++i;
                }
                if (plus == 1) {
                    // a/b  plus c/d
                    // (a*d plus b*c)/a*d;
                    // cout << a << " " << b << " " << c << " " << d << endl;
                    // cout << "sign " << plus << endl;
                    st.push(a * d + b * c);
                    if (a * d + b * c == 0)
                        st.push(1);
                    else
                        st.push(b * d);

                } else {
                    // cout << a << " " << b << " " << c << " " << d << endl;
                    // cout << "sign " << plus << endl;
                    st.push(a * d - b * c);
                    if (a * d + b * c == 0)
                        st.push(1);
                    else
                        st.push(b * d);
                }

            } else {
                int d = st.top();
                st.pop();
                int c = st.top();
                // cout << a << " " << b << " " << c << " " << d << endl;
                // cout << "sign " << f << endl;
                st.pop();
                // if (f == 1) {
                st.push(a * d + b * c);
                if (a * d + b * c == 0)
                    st.push(1);
                else
                    st.push(b * d);
                // } else {
                //     st.push(-1*a * d + b * c);
                //     st.push(b * d);
                // }
            }
        }
        int a, b;
        if (!st.empty()) {
            b = st.top();
            st.pop();
        }
        if (!st.empty()) {
            a = st.top();
            st.pop();
        }
        int gcd=__gcd(abs(a),abs(b));
        if(gcd==1) return to_string(a) + "/" + to_string(b);
        else
            return to_string(a / gcd) + "/" + to_string(b/gcd);
        
            
    }
};