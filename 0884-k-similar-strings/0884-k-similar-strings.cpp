class Solution {
    // ,vector<vector<int>>&idxs
    // int dp[21];
    map<pair<string,int>,int>dp;
    int solve(int i,string &s1, string &s2){
        if(i>=s1.size()) return 0;
        if(dp.count({s1,i})) return dp[{s1,i}];
        // if(dp[i]!=-1) return dp[i];
        if(s1[i]==s2[i]){
            return dp[{s1,i}] =  solve(i+1,s1,s2);
        }else{
            int ans=1e9;
            for(int j=i+1;j<s1.size();++j){
                if(s1[j]==s2[i]){
                    swap(s1[j],s1[i]);
                    ans=min(ans,1+solve(i+1,s1,s2));
                    swap(s1[j],s1[i]);
                }
            }
            return dp[{s1,i}]  = ans;
        }
    }
public:
    int kSimilarity(string s1, string s2) {
        // vector<vector<int>>idxs(26);
        // for(int i=0;i<s1.size();++i){
        //     idxs[s1[i]-'a'].push_back(i);
        // }
        // memset(dp,-1,sizeof(dp));
        return solve(0,s1,s2);
    }
};