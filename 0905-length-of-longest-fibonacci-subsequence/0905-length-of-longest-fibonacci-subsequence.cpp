class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        // Store index of each element
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]] = i;
        }
        int n=arr.size();
        for (int i = 0; i < arr.size() && (n-i+1>ans); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int req = arr[i] + arr[j]; 
                int idx = j, idx1 = i;
                int l = 2;  

               while (mp.find(req) != mp.end() && mp[req] > idx) {
                    idx1 = idx;
                    idx = mp[req];
                    req = arr[idx1] + arr[idx];  
                    ++l;
                }

                if (l > 2) ans = max(ans, l);
            }
        }
        return ans;
    }
};
