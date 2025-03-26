class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if(s1.empty() || s1==s2) return 0;
        for(int i=0;i<s1.size();++i){
          if(s1[i]==s2[i]){
            return kSimilarity(s1.substr(i+1),s2.substr(i+1));
          }else{
            vector<int>matches;
            for(int j=i+1;j<s1.size();++j){
              if(s1[j]==s2[i]){
                if(s2[j]==s1[i]){
                  swap(s1[i],s1[j]);
                  return 1+kSimilarity(s1.substr(i+1),s2.substr(i+1));
                }else{
                  matches.push_back(j);
                }
              }
            }
            int ans=1e9;
            for(auto&j:matches){
              swap(s1[i],s1[j]);
              ans=min(ans,1+kSimilarity(s1.substr(i+1),s2.substr(i+1)));
              swap(s1[i],s1[j]);
            }
            return ans;
          }
        }
        return 0;
    }
};