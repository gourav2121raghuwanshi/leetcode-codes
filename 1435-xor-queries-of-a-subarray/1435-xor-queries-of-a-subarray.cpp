class Solution {
    vector<int> seg;

    void build(int idx, int low, int high, vector<int>& a) {
        if (low == high) {
            seg[idx] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        if (low >= l && high <= r) // total overlap
            return seg[idx];
        if (high < l || low > r) // no overlap
            return 0;
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left ^ right;
    }

public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
        vector<int> ans;
        for (auto& i : queries) {
            int a = i[0];
            int b = i[1];
            ans.push_back(query(0, 0, n - 1, a, b));
        }
        return ans;
    }
};