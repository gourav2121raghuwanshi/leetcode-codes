class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto&i:s){
            if(i=='}' || i==']' || i==')'){
                if(st.empty()) return false;
                if(i=='}'){
                    if(st.top()!='{') return false;
                }
                else if(i==']'){
                    if(st.top()!='[') return false;
                }else if(st.top()!='(') return false;
                st.pop();
            }else{
                st.push(i);
            }
        }
        return st.empty();
    }
};