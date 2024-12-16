class Solution {

public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int>primes(n+1,true);

        primes[0]=primes[1]=false;
        for(int i=2;i<n;++i){
            if(primes[i]){
                for(long long j=i*1LL*i;j<n;j+=i){
                    primes[j]=false;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(primes[i]) ++ans;
        }
        return ans;
    }
};