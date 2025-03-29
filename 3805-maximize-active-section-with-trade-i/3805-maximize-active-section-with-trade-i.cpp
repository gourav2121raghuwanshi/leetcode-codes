class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int startzidx=-1;
        int endzidx=-1;
        for(int i=0;i<s.size();++i){
            if(s[i]=='0'){
                startzidx=i;
                break;
            }
        }
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='0'){
                endzidx=i;
                break;
            }
        }
        
        if(endzidx==startzidx){
            int c=0;
            for(auto&i:s){
                if(i=='1') ++c;
            }
            return c;
        }
        vector<pair<int,int>>v; //count,one or zero
        int count = 0;
        bool isOne = (s[0] == '1');

        // Construct the vector of consecutive groups of "1"s and "0"s
        for (char c : s) {
            if ((c == '1' && isOne) || (c == '0' && !isOne)) {
                count++;
            } else {
                v.push_back({count, isOne});
                count = 1;
                isOne = !isOne;
            }
        }
        v.push_back({count, isOne});

        int ans=0;
        int maxzerolen=0;
        for(int i=0;i<v.size();++i){
            int cnt=v[i].first;
            int one=v[i].second;
            if(one && i-1>=0 && i+1<(int)v.size() && v[i-1].second==false && 
                v[i+1].second==false ){
                maxzerolen=max(maxzerolen,v[i+1].first+v[i-1].first);
                }
            if(one) ans+=cnt;
        }
        return ans+maxzerolen;
    }

};