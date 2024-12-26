class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        vector<bool>valid(s.size(),false);
        stack<int>st;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]==')'){
                    if(st.empty()) continue;
                    else if(s[st.top()]=='('){
                        valid[st.top()]=true;
                        valid[i]=true;
                        st.pop();
                    }
                }else{
                    st.push(i);
                }
            }
        }
        for(int i=0;i<s.size();++i){
            if(valid[i] || (s[i]!='(' && s[i]!=')')){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};