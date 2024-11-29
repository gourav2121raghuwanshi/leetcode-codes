class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n=s.size();
        int size=n/k;
        unordered_map<string,int>mp;
        int i=0;
        while(i<s.size()){
            string a=s.substr(i,size);
            ++mp[a];
            i+=size;
        }
        for(auto&i:mp){
            cout<<i.first<<" ,";
        }
        int j=0;
        while(j<t.size()){
            string a =t.substr(j,size);
            if(mp[a]<=0) return false;
            --mp[a];
            j+=size;
        }
        return true;
    }
};