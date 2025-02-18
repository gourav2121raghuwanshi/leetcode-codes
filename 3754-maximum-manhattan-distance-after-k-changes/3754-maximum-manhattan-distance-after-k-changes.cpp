class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char, int> freq;
        int mf = 0;
        for (auto& i : s) {
            ++freq[i];
            mf = max(mf, freq[i]);
        }
        if (freq.size() == 1) {
            return mf;
        }
        int ans=0;
        vector<string> dir = {"NE", "ES", "SW", "NW"};
        for(auto&i:dir){
            int temp=k;
            int x=0;
            int y=0;
            for(auto&j:s){
                if(j==i[0] || j==i[1]){
                    if(j=='E' || j=='W') ++x;
                    else ++y;
                }else if(temp>0){
                    ++x;
                    --temp;
                }else{
                    --x;
                }
                ans=max(ans,x+y);
            }
        }
        return ans;
    }
};