class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>v(5,0);
        // a 0
        // e 1
        // i 2
        // o 3
        // u 4
        map<vector<int>,int>mp;
        mp[v]=-1;
        unordered_set<char>st={'a','e','i','o','u'};
        unordered_map<char,int>mapping;
        mapping['a']=0;
        mapping['e']=1;
        mapping['i']=2;
        mapping['o']=3;
        mapping['u']=4;
        int ans=0;
        for(int j=0;j<s.size();++j){
            char curr=s[j];
            if(st.count(curr)){
                ++v[mapping[curr]];
                v[mapping[curr]]%=2;
            }
            if(mp.count(v)){
                ans=max(ans,j-mp[v]);
            }else{
                mp[v]=j;
            }
        }
        return ans;
    }
};