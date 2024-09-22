class Solution {
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]>b[i]) return false;
        }
        return true;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(m>n) return 0;
        vector<int>a(26,0),b(26,0);
        for(auto&i:word2){
            ++a[i-'a'];
        }
        int s=0;
        long long ans=0;
        for(int e=0;e<n;e++){
            ++b[word1[e]-'a'];
            while(check(a,b)){
                ans+=1LL*(n-e);
                --b[word1[s]-'a'];
                ++s;
            }
        }
        return ans;
    }
};