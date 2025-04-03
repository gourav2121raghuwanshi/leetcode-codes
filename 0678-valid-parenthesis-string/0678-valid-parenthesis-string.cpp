class Solution {
public:
    bool checkValidString(string s) {
        // range : mini to maxi
        // if mini is 0, then possible
        int mini = 0;
        int maxi = 0;
        
        for (auto &i : s) {
            if (i == '(') {
                ++mini;
                ++maxi;
            } else if (i == ')') {
                --mini;
                --maxi;
            } else { // '*' can be '(', ')' or ''
                --mini; // Ensure mini is never negative
                ++maxi;
            }
            
            if (maxi < 0) return false; // Too many ')'
            if(mini<0) mini=0;
        }
        
        return mini == 0; // If mini is 0, it's a valid string
    }
};
