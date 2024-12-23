class Solution {
    unordered_set<string>st;
    void solve(string s,string tiles,vector<bool>&taken){
        if(!s.empty()){
            st.insert(s);
        }
        for(int i=0;i<tiles.size();++i){
            if(taken[i]==false){
                taken[i]=true;
                solve(s+tiles[i],tiles,taken);
                taken[i]=false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        vector<bool>taken(tiles.size(),false);
        solve("",tiles,taken);
        return st.size();
    }
};