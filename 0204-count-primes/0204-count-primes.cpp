class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<int>ans(n,true);
        ans[0]=ans[1]=false;
        for(int i=2;i*i<n;++i){
            if(ans[i]){
                for(int j=i*2;j<n;j+=i) ans[j]=false;
            }
        }
        int c=0;
        for(auto&i:ans){
            if(i) ++c;
        }
        return c;
    }
};