class Solution {
    int dp[1001];
    int solve(int i,vector<vector<int>>& books, int width){
        if(i>=books.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int currwidth=0;
        int ans=1e9;
        int currMaxH=-1e9;
        for(int j=i;j<books.size();++j){
            if(currwidth+books[j][0]<=width){
                currMaxH=max(currMaxH,books[j][1]);
                currwidth+=books[j][0];
                ans=min(ans,currMaxH+solve(j+1,books,width));
            }else break;
        }
        return dp[i]= ans;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
     return solve(0,books,shelfWidth)   ;
    }
};