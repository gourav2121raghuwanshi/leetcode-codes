class NumArray {
    vector<int> seg;
    int n;
void build(int idx, int low, int high, vector<int> &a) {
    if (low == high) {
        seg[idx] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, a);
    build(2 * idx + 2, mid + 1, high, a);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int query(int idx, int low, int high, int l, int r) {
    if (low >= l && high <= r) // total overlap
        return seg[idx];
    if (high < l || low > r) // no overlap
        return 0;
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return left + right;
}

void pointUpdate(int idx, int low, int high, int node, int val) {
    if (low == high) {
        seg[idx] = val;
    } else {
        int mid = (low + high) / 2;
        if (node <= mid) {
            pointUpdate(2 * idx + 1, low, mid, node, val);
        } else {
            pointUpdate(2 * idx + 2, mid + 1, high, node, val);
        }
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
}
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(n*4);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        pointUpdate(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};