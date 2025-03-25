class Solution {
    // Video Reference : https://www.youtube.com/watch?v=L-KWU8W3OqE
    // approach : [1,3,5,2] , k=2
    // all possible partionts

    // ((1),(3,5,2)) score: 1+1+3+2 
    // ((1,3),(5,2)) score: 1+3+5+2
    // ((1,3,5),(2)) score: 1+5+2+2
    // observerve 1,2 are in all scores as they are 1st and last elements of array
    // hence discard them and the final answer won't get affected as we do substraction of maximum - minimum
    // ((1),(3,5,2)) score: 1+3
    // ((1,3),(5,2)) score: 3+5
    // ((1,3,5),(2)) score: 5+2
    // observe
    // they are notiing but pair sum of array
    // we need to take (k-1) paris from both start and end to get final anser

public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> PairSum(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            PairSum[i] = weights[i] + weights[i + 1];
        }
        sort(PairSum.begin(), PairSum.end());
        long long prefSumofKMinus1 = 0;
        long long SuffSumofKMinus1 = 0;
        for (int i = 0; i < k - 1; ++i) {
            prefSumofKMinus1 += PairSum[i];
            SuffSumofKMinus1 += PairSum[n - i - 2];
        }
        return SuffSumofKMinus1 - prefSumofKMinus1;
    }
};