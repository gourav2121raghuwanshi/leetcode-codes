class Solution {
    /*
    CurrentResult = result_so_Far - prevValue + (prevVaue * currValue);
    ✅ Is always correct for handling * after a + or - when parsing expressions like "2+3*4" in left-to-right       single-pass evaluation (without using a full operator precedence parser or stack), as long as you're careful with signs.
    // 3+2*4 (first * has to be evaluated)
// logic to evaluate * :
// Result_so_far - prevValue + currValue * prevValue
// ex: 2+3*4 
// Result_so_far=3+2 = 5
// prevValue=2
currValue=4
//  we got : 5 - 2 + 2*4 
// addition and substraction are simple
    */


    /*
    sending prevValue for next iteration 
    prevValue for + : => currValue
    prevValue for - : => -currValue
    prevValue for * : => prevValue*currValue
    */
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