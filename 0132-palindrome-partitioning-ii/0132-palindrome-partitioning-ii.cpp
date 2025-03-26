class Solution {
    bool isPal(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            ++i,--j;
        }
        return true;
    }
    vector<int>dp;
    int solve(int i,string&s){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int ans=1e9;
        for(int j=i;j<s.size();++j){
            temp.push_back(s[j]);
            if(isPal(temp)){
                ans=min(ans,1+solve(j+1,s));
            }
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
      dp.resize(s.size()+1,-1);
      return solve(0,s)-1 ; 
    }
};