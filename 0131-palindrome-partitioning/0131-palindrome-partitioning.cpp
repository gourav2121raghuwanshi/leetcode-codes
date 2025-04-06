class Solution {
    bool isPal(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            ++i,--j;
        }
        return true;
    }
     vector<vector<string>>ans;
     void solve(int i,string&s,vector<string>&v){
        if(i>=s.size()){
            ans.push_back(v);
            return;
        }
        string temp="";
        for(int j=i;j<s.size();++j){
            temp.push_back(s[j]);
            if(isPal(temp)){
                v.push_back(temp);
                solve(j+1,s,v);
                v.pop_back();
            }
        }
     }
public:
    vector<vector<string>> partition(string s) {
       vector<string>v;
       solve(0,s,v);
       return ans;
    }
};