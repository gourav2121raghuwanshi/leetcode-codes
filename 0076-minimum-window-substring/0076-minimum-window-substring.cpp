class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int len=1e9;
        int start=-1;
        
        for(auto&i:t){
            ++mp[i];
        }

        int req=mp.size();
        int l=0;
        for(int i=0;i<s.size();++i){
            --mp[s[i]];
            if(mp[s[i]]==0) --req;
            while(req==0){
                if(len>i-l+1){
                    len=i-l+1;
                    start=l;
                }
                ++mp[s[l]];
                if(mp[s[l]]>0){
                    ++req;
                }
                ++l;
            }
        }

        if(start==-1) return "";
        return s.substr(start,len);
    }
};