class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        unordered_set<int> ans;
        ans.insert(intervals[0][1] - 1);
        ans.insert(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = 0;
            for (auto& i : ans) {
                if (i >= a && i <= b) {
                    ++c;
                }
            }
            if (c >= 2)
                continue;
            else if (c == 1) {
                while (ans.count(b))
                    --b;
                ans.insert(b);
            } else {
                while (ans.count(b))
                    --b;
                ans.insert(b);
                --b;
                while (ans.count(b))
                    --b;
                ans.insert(b);
            }
        }

        return ans.size();
    }
};