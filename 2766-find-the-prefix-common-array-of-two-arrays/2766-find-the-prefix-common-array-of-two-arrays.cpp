class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int c = 0;
        vector<int> freq(51, 0); // Frequency array for tracking common elements
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == B[i]) {
                // If the current elements in A and B are the same
                if (freq[A[i]] == 0) {
                    ++c; // Count as common only if not already counted
                }
                ++freq[A[i]]; // Mark as counted
            } else {
                // Handle A[i]
                if (++freq[A[i]] == 2) {
                    ++c; // Count as common
                }
                // Handle B[i]
                if (++freq[B[i]] == 2) {
                    ++c; // Count as common
                }
            }
            ans.push_back(c);
        }
        
        return ans;
    }
};
