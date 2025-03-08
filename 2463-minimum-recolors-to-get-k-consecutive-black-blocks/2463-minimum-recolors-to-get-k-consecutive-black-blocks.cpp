class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int ans=1e9;
        for(int i=0; i <= n - k; ++i){
            int c=0;
            for(int j=i;j<i+k && j<n;j++){
                if(blocks[j]=='W') ++c;
            }
            ans=min(ans,c);
        }
        return ans;
    }
};