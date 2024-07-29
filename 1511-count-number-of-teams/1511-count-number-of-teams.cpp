class Solution {
    int dp[1001][1002][2][3];
    
    int  solve(int i,int prev,bool inc,int cnt,vector<int>& rating){
        if(cnt==3) return 1;
        if(i>=rating.size()) return 0;
        if(dp[i][prev+1][inc][cnt]!=-1) return dp[i][prev+1][inc][cnt];
        int ans=0;
        if(prev==-1 || ( inc && rating[i] > rating[prev] ) || ( inc==false && rating[i] < rating[prev])){
              ans+=solve(i+1,i,inc,1+cnt,rating);
        }
        int ntake=solve(i+1,prev,inc,cnt,rating);
        ans+=ntake;
        return  dp[i][prev+1][inc][cnt]=ans;
        
        
    }
public:
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,true,0,rating)+solve(0,-1,false,0,rating);
    }
};