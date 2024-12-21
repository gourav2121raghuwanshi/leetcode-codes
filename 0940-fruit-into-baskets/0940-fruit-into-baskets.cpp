class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        unordered_map<int,int>mp;
        int s=0;
        for(int i=0;i<fruits.size();++i){
            ++mp[fruits[i]];
            while(mp.size()>2){
                --mp[fruits[s]];
                if(mp[fruits[s]]==0) mp.erase(fruits[s]);
                ++s;
            }
            ans=max(ans,i-s+1);
        }
        return ans;
    }
};