class Solution {
    bool diffParity(int a, int b) {
        return (a % 2 && b % 2 == 0) || (a % 2 == 0 && b % 2);
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<long long> pref(n+1, 0);
        if (n == 1) {
            ans.resize(queries.size(), true);
            return ans;
        }
   
        for (int i = 1; i < n; i++) {
            if (diffParity(nums[i], nums[i - 1])) {
                pref[i]=pref[i-1];
                continue;
            } else {
                pref[i] += 1+pref[i-1];
                // pref[i - 1] += 1;
            }
        }

     
        for (auto& i : queries) {
            int l = i[0];
            int r = i[1];
            if (l == 0) {
                int val = pref[r];
                if (val)
                    ans.push_back(false);
                else
                    ans.push_back(true);
            } else {
                int val = pref[r] - pref[l];
                if (val)
                    ans.push_back(false);
                else
                    ans.push_back(true);
            }
        }
        return ans;
        // 3,4,1,2,6
        // ok,ok,ok,ok,nok

        // 4,3,1,6
        // ok,ok,nok,ok
    }
};