class Solution {
    // int dp[16];
    unordered_map<string,int>dp;
    string getKey(vector<int>&freq){
        string s;
        for(auto&i:freq){
            s.push_back(i+'0');
        }
        return s;
    }
    int solve(vector<string>& stickers,vector<int>&freq){
        int sum=accumulate(freq.begin(),freq.end(),0);
        if(sum==0) return 0;
        string key=getKey(freq);
        if(dp.count(key)) return dp[key];
        // if(dp[i]!=-1) return dp[i];
        int ans=1e7;
        for(auto&s:stickers){
            vector<int>org=freq;
            for(int j=0;j<s.size();++j){
               if(freq[s[j]-'a']>0){
                freq[s[j]-'a']--;
                ans=min(ans,1+solve(stickers,freq));
               }
            }
            freq=org;
        }
        return  dp[key]=ans;
        // return dp[i] = ans;
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int>freq(26,0);
        for(auto&i:target){
            ++freq[i-'a'];
        }
        int ans= solve(stickers,freq);
        return ans>=1e7?-1:ans;
    }
};