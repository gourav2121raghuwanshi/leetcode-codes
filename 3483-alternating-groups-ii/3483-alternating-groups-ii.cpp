class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // {0,1,0,1,0},0,1,0,1,0
        int n=colors.size();
        colors.insert(colors.end(),colors.begin(),colors.end());
        vector<int>pref(colors.size());
        int c=0;
        pref[0]=0;
        for(int i=1;i<colors.size();++i){
            if(colors[i]==colors[i-1]) ++c;
            pref[i]=c;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int next=i+k-1;
            if(pref[next]-pref[i]==0){
                ++ans;
            }
        }
        return ans;
    }
};