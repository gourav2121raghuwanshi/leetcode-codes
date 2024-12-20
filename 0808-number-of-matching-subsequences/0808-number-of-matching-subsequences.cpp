class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.size();++i){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto&i:words){
          if(mp.count(i[0])) {
            
            bool f=true;
            int idx=-1;
            for(auto&ch:i){
                if(!mp.count(ch)){
                    f=false;
                    break;
                }
                auto ii=upper_bound(mp[ch].begin(),mp[ch].end(),idx);
                if(ii==mp[ch].end()){
                    f=false;
                    break;
                }
                idx=*ii;
            }
            if(f){
                ++ans;
            }
          }
        }
        return ans;
    }
};