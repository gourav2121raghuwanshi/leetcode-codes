class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> gap;
        int n = endTime.size();

        gap.push_back(startTime[0]);
        for (int i = 1; i < n; ++i) {
            gap.push_back(startTime[i] - endTime[i - 1]);
        }
        gap.push_back(eventTime - endTime.back());

        int s = 0, sum = 0, maxi = 0;
        int gapSize = gap.size();

        for (int e = 0; e < k + 1; e++)
            sum += gap[e];
        maxi = sum;

        for (int e = k + 1; e < gapSize; ++e) {
            sum -= gap[s++];
            sum += gap[e];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
