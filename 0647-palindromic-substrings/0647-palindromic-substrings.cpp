class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            // odd
                int l=i;
                int r=i+1;
                while(l>=0 && r<s.size() && s[l]==s[r]){
                    --l,++r;
                    ++ans;
                }


            // even
            l=i;
            r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                    --l,++r;
                    ++ans;
                }
        }
        return ans;
    }
};