class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pref(n + 1, 0);

        // Update prefix array based on shifts
        for (auto& shift : shifts) {
            int l = shift[0], r = shift[1], dir = shift[2];
            if (dir) {
                pref[l]++;
                pref[r + 1]--;
            } else {
                pref[l]--;
                pref[r + 1]++;
            }
        }

        // Apply shifts to the string
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += pref[i];
            sum = (sum % 26 + 26) % 26; // Normalize sum to be within [0, 25]

            // Shift the character
            s[i] = 'a' + (s[i] - 'a' + sum) % 26;
        }

        return s;
    }
};
