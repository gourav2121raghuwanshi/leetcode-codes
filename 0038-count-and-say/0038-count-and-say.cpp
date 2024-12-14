class Solution {
    string solve(int n,string s){
        if(n==1) return s;
        // int c=0;
        string t;
        int c=1;
        for(int i=1;i<s.size();++i){
            if(s[i]==s[i-1]){
                ++c;
            }else{
                t+=to_string(c);
                t.push_back(s[i-1]);
                c=1;
            }
        }
        t+=to_string(c);
        t.push_back(s.back());
        return solve(n-1,t);
    }
public:
    string countAndSay(int n) {
        return solve(n,"1");
    }
};