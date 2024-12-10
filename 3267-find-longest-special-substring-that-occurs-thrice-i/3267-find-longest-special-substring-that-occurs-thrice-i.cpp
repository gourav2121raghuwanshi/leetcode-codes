class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int>mp;
        int ans=0;
        for(int i=0;i<s.size();++i){
            char ch=s[i];
            int l=0;
            for(int j=i;j<s.size();++j){
                if(s[j]==ch) {
                ++l;
                mp[{ch,l}]++;}
            else break;
            }
        }
        for(auto&i:mp){
            int len=i.first.second;
            int freq=i.second;
            if(freq>=3){
                ans=max(ans,len);
            }
        }
        return ans==0?-1:ans;
    }
};