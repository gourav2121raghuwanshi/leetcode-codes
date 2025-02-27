class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        // Store index of each element
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int req = arr[i] + arr[j]; 
                int idx = j, idx1 = i;
                int l = 2;  // Reset length for each new pair
                
                // Continue while `req` exists in the map and its index is greater than `idx`
                while (mp.find(req) != mp.end() && mp[req] > idx) {
                    idx1 = idx;
                    idx = mp[req];
                    req = arr[idx1] + arr[idx];  // Update `req` correctly
                    ++l;
                }

                if (l > 2) ans = max(ans, l);
            }
        }
        return ans;
    }
};
