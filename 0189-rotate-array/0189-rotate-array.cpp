class Solution {
    void rev(vector<int>& nums, int s, int n) {
        int l = s;
        int r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            ++l,--r;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0)
            return;
        rev(nums, 0, n);
        cout << endl;
        rev(nums, 0, k);
        cout << endl;
        cout << k + 1;
        rev(nums, k, n);
    }
};