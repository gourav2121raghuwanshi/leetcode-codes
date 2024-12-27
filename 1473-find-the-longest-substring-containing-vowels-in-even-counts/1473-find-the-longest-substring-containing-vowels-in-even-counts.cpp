class Solution {
public:
    int findTheLongestSubstring(string s) {
       vector<int>freq(5,0) ;
       unordered_map<char,int>mapping;
       mapping['a']=0;
       mapping['e']=1;
       mapping['i']=2;
       mapping['o']=3;
       mapping['u']=4;

       unordered_set<char>st={
        'a','e','i','o','u'
       };
       map<vector<int>,int>mp;
       mp[freq]=-1;

        int ans=0;

        for(int i=0;i<s.size();++i){
            if(st.count(s[i])){
            ++freq[mapping[s[i]]];
            freq[mapping[s[i]]]%=2;
            }
            if(mp.count(freq)){
                ans=max(ans,i-mp[freq]);
            }else{
                mp[freq]=i;
            }
        }

        return ans; 
    }
};