class Solution {
    vector<int> seg;

    void build(int idx, int low, int high, vector<int>& a) {
        if (low == high) {
            seg[idx] = low; // Store the index of the single element
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);

        int leftidx = seg[2 * idx + 1];
        int rightidx = seg[2 * idx + 2];

        // Store the index of the maximum element in the current range
        seg[idx] = (a[leftidx] >= a[rightidx]) ? leftidx : rightidx;
    }

    int query(int idx, int low, int high, int l, int r, vector<int>& a) {
        if (low >= l && high <= r) // Total overlap
            return seg[idx];       // Return the index of the maximum element

        if (high < l || low > r) // No overlap
            return -1;

        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r, a);
        int right = query(2 * idx + 2, mid + 1, high, l, r, a);

        if (left == -1)
            return right;
        if (right == -1)
            return left;

        // Compare the values in the original array
        return (a[left] >= a[right]) ? left : right;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        int n = heights.size();

        // construct segment tree
        seg.resize(n * 4);
        vector<int> ans;
        build(0, 0, n - 1, heights);


        for (auto& i : queries) {
            int maxi = max(i[0], i[1]);
            int mini = min(i[0], i[1]);

            if (mini == maxi)
                ans.push_back(mini);
            else if (heights[maxi] > heights[mini]) {
                ans.push_back(maxi);
            } else {
                int l = maxi + 1;
                int r = n - 1;
                int ansidx = INT_MAX;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    int idx = query(0,0,n-1,l,mid,heights);
                    if (heights[idx] > max(heights[mini], heights[maxi])) {
                        ansidx = min(idx, ansidx);
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
                int val=ansidx==INT_MAX?-1:ansidx;
                ans.push_back(val);
            }
        }
        return ans;
    }
};
