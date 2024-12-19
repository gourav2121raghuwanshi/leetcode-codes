class Solution {
    int ans=0;
    void solve(int j,int val,int n){
        if(j==n+1) ++ans;
        if(j>n+1) return;

        for(int i=1;i<=n;++i){
            if(val&(1<<i) && (i%j==0 || j%i==0)){
                val^=(1<<i);
                solve(j+1,val,n);
                val^=(1<<i);
            }
        }
    }
public:
    int countArrangement(int n) {
        int val=(1<<(n+1))-1;
        solve(1,val,n);
        return ans;
    }
};