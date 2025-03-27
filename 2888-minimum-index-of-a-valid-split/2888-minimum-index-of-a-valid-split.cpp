class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ele = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (ele == nums[i])
                ++cnt;
            else {
                --cnt;
            }
            if (cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
        }
        int totalCnt = 0;
        for (auto& i : nums) {
            if (i == ele)
                ++totalCnt;
        }
        int tillCount = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == ele)
                ++tillCount;
            int inSubarray1Len = i + 1;
            int inSubarray2Len = n - i - 1;
            int leftCount = totalCnt - tillCount;
            if (tillCount > inSubarray1Len / 2 && leftCount > inSubarray2Len / 2) {
                return i;
            }
        }
        return -1;
    }
};