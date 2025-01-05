class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.size();++i){
            int curr=s[i]-'a';
            int mirror=25-curr;
            if(mp[mirror].size()){
                ans+=(i-mp[mirror].back());
                mp[mirror].pop_back();
            }else{
                mp[curr].push_back(i);
            }
        }

        return ans;
    }
};