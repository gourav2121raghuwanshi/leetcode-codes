class Solution {
    bool solve(int i,int req,vector<int>&side,vector<int>&matchsticks){
        if(i==matchsticks.size()){
            for(auto&j:side) if(j!=req) return false;
            return true;
        }
        for(int j=0;j<4;++j){
            if(side[j]+matchsticks[i]<=req){
                side[j]+=matchsticks[i];
                if(solve(i+1,req,side,matchsticks)) return true;
                side[j]-=matchsticks[i];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        
        int req=sum/4;
        if(matchsticks[0]>req){
            return false;
        }
        vector<int>side(4,0);
        return solve(0,req,side,matchsticks);


    }
};