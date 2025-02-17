class Solution {
    unordered_set<string>st;
    void solve(string &s,string &t,vector<bool>&taken){
        if(!t.empty()) st.insert(t);

       for(int i=0;i<s.size();++i){
        if(!taken[i]){
            taken[i]=1;
            t.push_back(s[i]);
            solve(s,t,taken);
            t.pop_back();
            taken[i]=0;
        }
       }
    }
public:
    int numTilePossibilities(string tiles) {
        
        vector<bool>taken(tiles.size(),false);
        string t;
        solve(tiles,t,taken);

        return st.size();
    }
};