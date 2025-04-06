class Solution {
// Three Concepts for this Problem

/***************************** Concept 1 *****************************************
To correctly evaluate expressions like "2+3*4" in a single left-to-right pass,
we use the formula:

    result_so_far = result_so_far - prevValue + (prevValue * currValue);

✅ This correctly handles * (multiplication) after + or - without using a full
   expression parser or operator precedence.

Example:
    Expression: 2+3*4
    After evaluating 2+3 → result_so_far = 5
    prevValue = 3, currValue = 4

    So we compute: 5 - 3 + 3*4 = 14 ✅
--------------------------------------------------------------------------------*/

/********************************* Concept 2 *****************************************
Carry the correct prevValue into the next recursive call:

- For + : prevValue =  currValue
- For - : prevValue = -currValue
- For * : prevValue =  prevValue * currValue
--------------------------------------------------------------------------------*/

/********************************* Concept 3 *****************************************
To avoid forming numbers with leading zeros (e.g., "05", "003"):

    if (j > i && num[i] == '0') break;

This allows a single '0' but skips any longer number starting with '0'.

Example:
    Input: "105"
    i = 1, num[i] = '0'

    num.substr(1, 1) → "0" ✅
    num.substr(1, 2) → "05" ❌ (leading zero, invalid)
--------------------------------------------------------------------------------*/

    vector<string> ans;
    void solve(string& num, int target, int i, string path, long long prevValue,
               long long result_so_far) {
        if (i >= num.size()) {
            if (target == result_so_far) {
                ans.push_back(path);
            }
            return;
        }
        long long currValue = 0;
        for (int j = i; j < num.size(); ++j) {
            if (j > i && num[i] == '0')     // to avoid leading zeros and to consider trailing zeroes
                break; /* s = "105"
                i = 1, and s[i] == '0'
                Then s.substr(1, 1) is "0" (which is OK),
                but s.substr(1, 2) is "05" (which is ❌ because of leading zero).
                */
            currValue = currValue * 10 + (num[j] - '0');
            if (i == 0) {
                solve(num, target, j + 1, to_string(currValue), currValue,
                      currValue);
            } else {
                solve(num, target, j + 1, path + "+" + to_string(currValue),
                      currValue, result_so_far + currValue);
                solve(num, target, j + 1, path + "-" + to_string(currValue),
                      -currValue, result_so_far - currValue);
                solve(num, target, j + 1, path + "*" + to_string(currValue),
                     prevValue* currValue,
                      (result_so_far - prevValue) + (prevValue * currValue));
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, "", 0, 0);

        return ans;
    }
};