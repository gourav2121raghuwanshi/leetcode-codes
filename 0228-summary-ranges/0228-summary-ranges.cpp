class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        if (nums.size() == 1) {
            return {to_string(nums[0])};
        }
        string a;
        int start = nums[0];
        int temp = start;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - 1 == temp) {
                temp = nums[i];
            } else {
                // ans.push_back(to_string(start));
                if (temp != start) {
                    ans.push_back(to_string(start) + "->" + to_string(temp));
                    // ans.push_back("->");
                    // ans.push_back(to_string(temp));
                } else
                    ans.push_back(to_string(start));
                start = nums[i];
                temp = nums[i];
            }
        }

        if (temp != start) {
            ans.push_back(to_string(start) + "->" + to_string(temp));
        } else
            ans.push_back(to_string(start));
        return ans;
    }
};