class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        vector<int>freq(256,0);
        int ans=0;
        for(int e=0;e<s.size();++e){
            char i=s[e];
            ++freq[i];
            while(freq[i]>1){
                --freq[s[l]];
                ++l;
            }
            ans=max(ans,e-l+1);
        }
        return ans;
    }
};