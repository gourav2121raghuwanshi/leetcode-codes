class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int>mp;
        int ans=0;
        int s=0;
        for(int i=0;i<hours.size();++i){
            if(hours[i]>8) ++s;
            else --s;
            if(s>0) ans=i+1;
            else{
                if(!mp.count(s)) mp[s]=i;
                if(mp.count(s-1)){
                    ans=max(ans,i-mp[s-1]);
                }
            }
            
        }
        return ans;
    }
};