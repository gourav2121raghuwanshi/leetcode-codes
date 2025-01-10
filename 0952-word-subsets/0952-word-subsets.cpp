class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string>ans;
    vector<vector<int>>freq;
    vector<int>maxReq(26,0);
    for(auto&i:words2){
        vector<int>v(26,0);
        for(auto&j:i){
            ++v[j-'a'];
        }
        for(int j=0;j<26;j++){
            maxReq[j]=max(maxReq[j],v[j]);
        }
    }
    
    for(int kk=0;kk<words1.size();++kk){
        string i=words1[kk];
        bool f=true;
        vector<int>v(26,0);
        for(auto&j:i){
            ++v[j-'a'];
        }
    
        
            for(int j=0;j<26;j++){
                if(maxReq[j]>v[j]){
                    f=false;
                    break;
                }
            
        }
         
        if(f) ans.push_back(i);
    }
    return ans;
    }
};