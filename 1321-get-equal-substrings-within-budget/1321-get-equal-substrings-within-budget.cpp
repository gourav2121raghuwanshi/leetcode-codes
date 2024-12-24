class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0;
        int mlen=0;
        int val=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            val+=abs(s[i]-t[i]);
            while(val>maxCost){
                val-=abs(s[l]-t[l]);
                ++l;
            }
            mlen=max(mlen,i-l+1);
        }
        return mlen;
    }
};