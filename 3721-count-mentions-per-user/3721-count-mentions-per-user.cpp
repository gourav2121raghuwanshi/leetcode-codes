class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // Sort events: first by timestamp, then prioritize "OFFLINE" before "MESSAGE"
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            if (stoi(a[1]) != stoi(b[1])) return stoi(a[1]) < stoi(b[1]);
            return a[0] > b[0]; // "OFFLINE" should come before "MESSAGE"
        });

        vector<int> ans(numberOfUsers, 0);
        unordered_set<int> offline;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& event : events) {
            int time = stoi(event[1]);

            // Bring users back online if their offline time has expired
            while (!pq.empty() && pq.top().first <= time) {
                int id = pq.top().second;
                pq.pop();
                offline.erase(id);
            }

            if (event[0] == "MESSAGE") {
                string mentions_str = event[2];

                if (mentions_str == "HERE") {
                    // Mention all online users
                    for (int j = 0; j < numberOfUsers; ++j) {
                        if (offline.find(j) == offline.end()) {
                            ans[j]++;
                        }
                    }
                } else if (mentions_str == "ALL") {
                    // Mention all users
                    for (int j = 0; j < numberOfUsers; ++j) {
                        ans[j]++;
                    }
                } else {
                    // Mentions list parsing
                    stringstream ss(mentions_str);
                    string mention;
                    while (ss >> mention) {
                        if (mention.substr(0, 2) == "id") {
                            int userId = stoi(mention.substr(2));
                            if (userId >= 0 && userId < numberOfUsers) {
                                ans[userId]++;
                            }
                        }
                    }
                }
            } else if (event[0] == "OFFLINE") {
                int id = stoi(event[2]);
                offline.insert(id);
                pq.push({time + 60, id}); // User comes back online after 60 time units
            }
        }

        return ans;
    }
};