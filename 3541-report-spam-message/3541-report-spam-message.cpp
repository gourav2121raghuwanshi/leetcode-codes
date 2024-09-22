class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st;
        for(auto&i:bannedWords){
            st.insert(i);
        }
        int c=0;
        for(auto&i:message){
            if(st.count(i)) ++c;
            if(c>=2) return true;
        }
        return false;
    }
};