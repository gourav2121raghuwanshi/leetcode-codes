class Solution {
    // int dp[16];
    unordered_map<string, int> dp;
    string getKey(vector<int>& freq) {
        string s;
        for (auto& i : freq) {
            s.push_back(i + '0');
        }
        return s;
    }
    // int solve(vector<string>& stickers,vector<int>&freq){
    //     int sum=accumulate(freq.begin(),freq.end(),0);
    //     if(sum==0) return 0;
    //     string key=getKey(freq);
    //     if(dp.count(key)) return dp[key];

    //     int ans=1e7;
    //     for(auto&s:stickers){
    //         vector<int>org=freq;
    //         for(int j=0;j<s.size();++j){
    //            if(freq[s[j]-'a']>0){
    //             freq[s[j]-'a']--;
    //             ans=min(ans,1+solve(stickers,freq));
    //            }
    //         }
    //         freq=org;
    //     }
    //     return  dp[key]=ans;
    //  }
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int> freq(26, 0);
        for (auto& i : target) {
            ++freq[i - 'a'];
        }
        queue<pair<vector<int>, int>> q;
        q.push({freq, 0});
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            vector<int> f = tp.first;
            int count = tp.second;
            for (auto& s : stickers) {
                vector<int> temp = f;
                bool taken = false;
                for (int j = 0; j < s.size(); ++j) {
                    if (temp[s[j] - 'a'] > 0) {
                        --temp[s[j] - 'a'];
                        taken = 1;
                    }
                }
                if (taken) {
                    int sum = accumulate(temp.begin(), temp.end(), 0);
                    if (sum == 0)
                        return count + 1;
                    string key = getKey(temp);
                    if (!dp.count(key)) {
                        dp[key] = count + 1;
                        q.push({temp, count + 1});
                    }
                }
            }
        }

        return -1;
        // int ans= solve(stickers,freq);
        // return ans>=1e7?-1:ans;
    }
};