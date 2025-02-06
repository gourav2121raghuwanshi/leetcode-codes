class Solution {
    const int MOD = 1e9 + 7;
long long modPower(long long x, long long y)
{
    long long res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

vector<long long> factorial;
vector<long long> inverseFactorial;
void preComputeFactorial_and_InverseFactorial(int n)
{
    factorial.resize(n + 1);
    inverseFactorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        factorial[i] = (factorial[i - 1] * 1LL * i) % MOD;
    }

    inverseFactorial[n] = modPower(factorial[n], MOD - 2);

    for (int i = n - 1; i >= 0; --i)
    {
        inverseFactorial[i] = (inverseFactorial[i + 1] * 1LL * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    return ((factorial[n] %MOD * inverseFactorial[r]%MOD)%MOD * inverseFactorial[n - r]) % MOD;
}
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,int>prod;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                ++prod[nums[i]*1LL*nums[j]];
            }
        }
        preComputeFactorial_and_InverseFactorial(1000);
        long long ans=0;
        for(auto&i:prod){
            if(i.second>1){
                ans+=8*nCr(i.second,2);
            }
        }
        return ans;
    }
};