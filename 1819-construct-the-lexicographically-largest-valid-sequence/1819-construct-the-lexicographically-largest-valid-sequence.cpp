class Solution {
    
    bool solve(int idx, vector<int>& freq, vector<int>& ans, int n) {

        if (idx == ans.size()) { // we have Reached a answer
            // since we want lexographically Largest , hence return upon getting
            // First answer as we had started From Back to Front
            return 1;
        }
        if (ans[idx] != -1) // already Occupied
            return solve(idx + 1, freq, ans, n);

        for (int i = n; i >= 1; --i) {
            if (freq[i] > 0) {
                --freq[i];     // Decrease the frequency
                ans[idx] = i; // Fill the idx
                if (i == 1) {  // 1 has to be placed only Once
                    bool a = solve(idx + 1, freq, ans, n);
                    if (a)
                        return a;
                } else if (i != 1 && idx + i < ans.size() &&
                           ans[idx + i] ==
                               -1) { // Others Twice at given Distance
                    ans[idx + i] = i;
                    --freq[i];
                    bool a = solve(idx + 1, freq, ans, n);
                    if (a)
                        return a;
                    // backTrack
                    ++freq[i];
                    ans[idx + i] = -1;
                }
                // backTrack
                ans[idx] = -1; // make Idx empty again
                ++freq[i];      // Increase elemets frequency
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {

        int req = 2 * n - 1; // Required Number of elements
        vector<int> freq(n + 1);  // required freq of elements
        // freq=1 (for 1) and 2 for all others
        freq[1] = 1; 
        for (int i = 2; i <= n; i++)
            freq[i] = 2;


        vector<int> ans(req, -1); 

        for (int i = n; i >= 1; i--) {
            --freq[i]; //take Once
            if (i != 1) { // if not 1 , take twice
                ans[i] = i;
                --freq[i];
            }
            ans[0] = i;
            if (solve(1, freq, ans, n))
                return ans;
            ++freq[i];
            ans[0]=-1;
             if (i != 1) {
                ans[i] = -1;
                ++freq[i];
            }
        }
        return ans;
    }
};