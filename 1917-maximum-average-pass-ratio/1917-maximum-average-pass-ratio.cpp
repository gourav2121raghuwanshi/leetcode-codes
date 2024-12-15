class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;

        // Populate the priority queue with the initial gains
        for (auto& c : classes) {
            int pass = c[0], total = c[1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, {pass, total}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            // Update the class with one extra student
            pass++;
            total++;

            // Recalculate the gain and push back into the priority queue
            double newGain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({newGain, {pass, total}});
        }

        // Calculate the final average pass ratio
        double ans = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            ans += (double)pass / total;
        }

        return ans / classes.size();
    }
};
