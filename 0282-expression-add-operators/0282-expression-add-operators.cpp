// 3+2*4 (first * has to be evaluated)
// logic to evaluate * :
// Result_so_far - prevValue + currValue * prevValue
// ex: 2+3*4
// Result_so_far=3+2 = 6
//  we got : 6 - 2 + 4*2
// addition and substraction are simple

class Solution {
    void solve(int i, string& s, int target, long long prevValue,
               long long resultTillNow, string currPath, vector<string>& ans) {
        if (i >= s.size()) {
            if (resultTillNow == target) {
                ans.push_back(currPath);
            }
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            // Avoid numbers with leading zeros
            if (j > i && s[i] == '0')
                break;
            // Extract the current number
            string currNumStr = s.substr(i, j - i + 1);
            long long currNum = stol(currNumStr);
            // Base case
            if (i == 0) {
                solve(j + 1, s, target, currNum, currNum, currNumStr, ans);
            } else {
                solve(j + 1, s, target, currNum, resultTillNow + currNum,
                      currPath + "+" + currNumStr, ans);
                solve(j + 1, s, target, -currNum, resultTillNow - currNum,
                      currPath + "-" + currNumStr, ans);
                solve(j + 1, s, target, prevValue * currNum,
                      resultTillNow - prevValue + (prevValue * currNum),
                      currPath + "*" + currNumStr, ans);
            }
        }
    }

public:
    vector<string> addOperators(string s, int t) {
        if (s.empty())
            return {};
        vector<string> ans;
        solve(0, s, t, 0, 0, "", ans);
        return ans;
    }
};
