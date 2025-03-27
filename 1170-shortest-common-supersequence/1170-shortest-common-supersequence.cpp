class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n=a.size();
        int m=b.size();
           int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ans;

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;++j){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        // int len=dp[n][m];
        // // cout<<len<<endl;
        // string ans(len,'#');
        // int idx=len-1;
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans.push_back(a[i-1]);
                --i,--j;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(a[i-1]);
                    --i;
                }else if(dp[i-1][j]<=dp[i][j-1]){
                    ans.push_back(b[j-1]);
                    --j;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(i>0){
            ans=a.substr(0,i)+ans;
        }
        if(j>0){
            ans=b.substr(0,j)+ans;
        }
        
        // cout<<ans<<endl;
        return ans;
    }
};