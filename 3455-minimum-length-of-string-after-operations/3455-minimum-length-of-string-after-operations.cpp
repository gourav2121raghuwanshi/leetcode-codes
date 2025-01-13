class Solution {
public:
    int minimumLength(string s) {
        vector<int>f(26,0);
        for(auto&i:s){
            ++f[i-'a'];
        }
        int ans=0;
        for(auto&i:f){
            if(i==0) continue;
            else if(i<=2) ans+=i;
            else{
                if(i&1) ++ans;
                else ans+=2;
            }
        }
        return ans;
    }
};