class Solution {
    int dp[101][101];
    bool solve(int i,string &s,int open){
        if(i==s.size()){
            return open==0;
        }
        if(open<0) return false;
        if(dp[i][open]!=-1) return dp[i][open];
        if(s[i]=='('){
            return dp[i][open] = solve(i+1,s,open+1);
        }else if(s[i]==')'){
            return dp[i][open] = solve(i+1,s,open-1);
        }else {
            return dp[i][open] = solve(i+1,s,open+1) || solve(i+1,s,open-1) || solve(i+1,s,open);
        }
    }
public:
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s,0);
    }
};