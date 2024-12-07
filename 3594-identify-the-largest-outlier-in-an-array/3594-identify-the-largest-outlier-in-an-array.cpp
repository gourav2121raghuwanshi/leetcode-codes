class Solution {
    // equation 2*(sum of special_numbers) + outlier = total_sum
    // special_numbers= sum of element representing the sum of that numbers.
    // hence we get s(special number)

public:
     int getLargestOutlier(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> freq;

        // Count the frequency of each number
        for (int num : nums) {
            ++freq[num];
        }

        int ans = INT_MIN;
        for (int num : nums) {
            int s = (sum - num);
            // Check if s is even and its half exists in the map
            if (s % 2 == 0 && freq.count(s / 2) ) {
                if(s/2==num && freq[num]==1) continue;  // number cannot be special and outlier at same time
                if (num > ans) { // Keep track of the largest outlier
                    ans = num;
                }
            }
        }
        return (ans == INT_MIN) ? -1 : ans; // Return -1 if no outlier found
    }
};