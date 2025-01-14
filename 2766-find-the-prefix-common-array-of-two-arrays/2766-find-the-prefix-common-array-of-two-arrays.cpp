class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int c = 0;
        vector<int> f1(51, 0), f2(51, 0);
        vector<bool> taken(51, 0);
        for (int i = 0; i < A.size(); ++i) {
            ++f1[A[i]];
            ++f2[B[i]];    

            if (f1[A[i]] && f2[A[i]] && !taken[A[i]]) {
                taken[A[i]] = true;
                ++c;
            }
            if (f1[B[i]] && f2[B[i]] && !taken[B[i]]) {
                taken[B[i]] = true;
                ++c;
            }

            ans.push_back(c);
        }

        return ans;
    }
};