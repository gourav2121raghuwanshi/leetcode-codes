class Solution {
    bool valid(int curr, int n, vector<int>& quantities) {
        int count = 0;  // Track the number of distributors needed
        
        for (auto& j : quantities) {
            // Calculate the number of distributors required for quantity `j`
            count += ceil(j*1.0 / curr*1.0);  // Ceiling of j / curr
            
            // If count exceeds available distributors, return false early
            if (count > n) return false;
        }
        
        return count <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1;  // Start with 1 (minimum possible max per distributor)
        int e = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        
        while (s <= e) {
            int mid = (s + e) / 2;
            if (valid(mid, n, quantities)) {
                ans = mid;
                e = mid - 1;  // Try for a smaller maximum value
            } else {
                s = mid + 1;  // Increase the maximum allowed per distributor
            }
        }
        
        return ans;
    }
};
