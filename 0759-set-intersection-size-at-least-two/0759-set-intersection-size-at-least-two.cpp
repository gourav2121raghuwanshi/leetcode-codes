class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        int ans = 2;
        int p1 = intervals[0][1] - 1;
        int p2 = intervals[0][1] ;
        for (int i = 1; i < intervals.size(); ++i) {
            cout<<p1<<","<<p2<<endl;
            int a = intervals[i][0];
            int b = intervals[i][1];
            if (a <= p1)
                continue;
            else if (a <= p2) {
                ++ans;
                if(p2==b){
                    p1=b-1;
                    continue;
                }
                p1 = p2;
                p2 = b;
            } else {
                ans += 2;
                p1 = b - 1;
                p2 = b;
            }
        }

        return ans;
    }
};