class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // Pair of character and its count

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++; // Increment count if the character matches the top
                if (st.top().second == k) {
                    st.pop(); // Remove if count reaches k
                }
            } else {
                st.push({c, 1}); // Push new character with count 1
            }
        }

        // Reconstruct the string
        string result = "";
        while (!st.empty()) {
            result.insert(result.begin(), st.top().second, st.top().first);
            st.pop();
        }

        return result;
    }
};
