class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip '_' in both strings
            while (i < n && start[i] == '_') ++i;
            while (j < n && target[j] == '_') ++j;

            // If one reaches the end and the other doesn't, invalid
            if ((i < n) != (j < n)) return false;

            // Check character mismatches
            if (i < n && j < n) {
                if (start[i] != target[j]) return false;

                // 'L' must not move right and 'R' must not move left
                if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                    return false;
                }

                ++i;
                ++j;
            }
        }

        return true;
    }
};
