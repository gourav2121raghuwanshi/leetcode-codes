class Solution {

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        unordered_set<int> left;
        set<int> right;

        int N = nums.size();
        int size1 = N / 2;
        int size2 = N - size1;
        for (int mask = 0; mask < (1 << size1); ++mask) {
            long long s = 0;
            for (int i = 0; i < size1; ++i) {
                if (mask & (1 << i)) {
                    s += nums[i];
                }
            }
            left.insert(s);
        }
        for (int mask = 0; mask < (1 << size2); ++mask) {
            long long s = 0;
            for (int i = 0; i < size2; ++i) {
                if (mask & (1 << i)) {
                    s += nums[i + size1];
                }
            }
            right.insert(s);
        }
        int ans = INT_MAX;
        for (auto&i:left){
            int req1=goal-i;
            auto it=right.lower_bound(req1);
            if(it==right.end()){
                --it;
            }
        
            ans=min(ans,abs(goal-(i+*it)));
            if(it!=right.begin()) --it;
            ans=min(ans,abs(goal-(i+*it)));
        }
        return ans;
    }
};