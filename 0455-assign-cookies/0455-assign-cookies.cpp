class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=g.size()-1;
        int j=s.size()-1;
        int ans=0;
        while(i>=0 && j>=0){
            if(g[i]<=s[j]) ++ans,--i,--j;
            else --i;
        }
        return ans;
    }
};