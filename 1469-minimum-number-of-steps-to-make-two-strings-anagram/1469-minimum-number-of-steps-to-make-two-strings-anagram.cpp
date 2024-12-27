class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(auto&i:s) ++f1[i-'a'];
        for(auto&i:t) ++f2[i-'a'];

        int ans=0;

        for(int i=0;i<26;i++){
            ans+=abs(f1[i]-f2[i]);
        }

        return (ans+1)/2;
    }
};