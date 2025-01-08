class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.size();++i){
            int mirror=25-(s[i]-'a');
            if(!mp[mirror].empty()){
                ans+=i-mp[mirror].back();
                mp[mirror].pop_back();
            }else{
                mp[s[i]-'a'].push_back(i);
            }
        }
        return ans;
    }
};