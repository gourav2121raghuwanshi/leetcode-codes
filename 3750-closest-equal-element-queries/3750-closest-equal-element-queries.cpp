class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }
        int n=nums.size();
        
        vector<int> v;
        for (int i : queries) {
            int val = nums[i];
            int ans = 1e9;
            vector<int>& indices = mp[val];
            auto it = lower_bound(indices.begin(), indices.end(), i);

            if (it != indices.begin()) {
                ans = min(ans, i - *(prev(it)));
                int lefti=*prev(it);
                int frontright=lefti+n-i;
                ans = min(ans,frontright);
                int first=mp[val][0];
                ans=min(ans,n-i-1+first+1);
            }

            if (next(it) != indices.end()) {
                ans = min(ans, *next(it) - i);
                int frontright=i+n-*next(it);
                 ans = min(ans,frontright);
                  int last=mp[val].back();
                ans=min(ans,n-last-1+i+1);
            }

            v.push_back(ans >= 1e9 ? -1 : ans);
        }
        return v;
    }
};

