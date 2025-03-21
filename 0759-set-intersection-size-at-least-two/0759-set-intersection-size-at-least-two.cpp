class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        // vector<int> ans;
        set<int> ans;
        ans.insert(intervals[0][1] - 1);
        ans.insert(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i) {
        
            int a = intervals[i][0];
            int b = intervals[i][1];
            int n = ans.size();
            auto it = ans.end();
            --it;
            auto it1 = it;
            --it1;
            if (a <= *it1) {
                continue;
            } else if (a <= *it) {
                if (*it != b)
                    ans.insert(b);
                else
                    ans.insert(b - 1);
            } else {
                if (*it != b)
                    ans.insert(b);
                else
                    ans.insert(b - 1);
                --b;
                auto it = ans.end();
                --it;
                if (*it != b)
                    ans.insert(b);
                else
                    ans.insert(b - 1);
            }
        }

        return ans.size();
    }
};