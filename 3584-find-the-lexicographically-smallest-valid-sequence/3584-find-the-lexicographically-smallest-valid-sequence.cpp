class Solution {
     set<pair<int, pair<int, int>>>st;
    bool solve(int i,int j,string &word1, string &word2,int c,vector<int>&idx){
        if(j>=word2.size()) return true;
        if(i>=word1.size()) return false;
        if(st.count({i,{j,c}})) return false;
        
        bool flag=false;
        if(word1[i]==word2[j]){    
            flag=solve(i+1,j+1,word1,word2,c,idx);
            if(flag){
            idx.push_back(i);
            return true;
        }
        }else{
             if(c>0){
            
            flag=solve(i+1,j+1,word1,word2,c-1,idx);
            if(flag){
            idx.push_back(i);
            return true;
        }
        }
        }
      
      while(i<word1.size() && word1[i]!=word2[j]) ++i;
      if(i<word1.size()){
        flag=solve(i+1,j+1,word1,word2,c,idx);
        if(flag){
            idx.push_back(i);
            return true;
        }
      }
        st.insert({i,{j,c}});
      return flag;
    }
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int>indices;
        if(solve(0,0,word1,word2,1,indices)){
            reverse(indices.begin(),indices.end());
            if(indices.size()==word2.size()) return indices;
        }

        
        return {};
    }
};