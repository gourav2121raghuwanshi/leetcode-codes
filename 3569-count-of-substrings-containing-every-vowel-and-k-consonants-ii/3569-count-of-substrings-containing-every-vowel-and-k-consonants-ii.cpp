class Solution {
    // Function to count substrings with at most k consonants and all vowels
    long long atMostK(string word, int k) {
        int n = word.size(), l = 0, cons = 0;
        long long count = 0;
        map<char, int> vowels;  // Track vowel counts

        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};  // Set of vowels
         
        for (int r = 0; r < n; r++) {
            // Check if the character is a vowel or consonant
            if (st.find(word[r]) != st.end()) 
                vowels[word[r]]++;  // Increment vowel count
            else 
                cons++;  // Increment consonant count

            // Shrink the window when we have all vowels and excess consonants
            while (vowels.size() == 5 && cons > k) {
                if (st.find(word[l]) != st.end()) {
                    vowels[word[l]]--;
                    if (vowels[word[l]] == 0)
                        vowels.erase(word[l]);  // Remove vowel if count reaches zero
                } else {
                    cons--;  // Decrement consonant count
                }
                l++;  // Move left pointer
            }

            // Count valid substrings ending at index `r`
            count += (r - l + 1);
        }
        return count;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return atMostK(word, k) - atMostK(word, k - 1);
    }
};
