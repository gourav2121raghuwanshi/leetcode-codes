class Solution {
    bool valid(int mid, vector<int>& candies, long long k) {
        long long total = 0;
        for (int &c : candies) {
            total += (c / mid);  
        }
        return total >= k;
    }
    
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (valid(mid, candies, k)) {
                ans = mid;  
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};
