class Solution {
public:
    int numberOfSubstrings(string s) {
        int la=-1;
        int lb=-1;
        int lc=-1;
        int ans=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='a') la=i;
            else if(s[i]=='b') lb=i;
            else lc=i;
            ans+=min({la,lb,lc})+1;
        }
        return ans;
    }
};