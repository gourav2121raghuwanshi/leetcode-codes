class Solution {
    long long solve(string curr, string suff, int limit) {
        if (curr.size() < suff.size())
            return 0;

        // if curr="1234" and suff="12"
        // we want "34" from curr to check if "34"<="12" -> ++count
        string trail=curr.substr(curr.size()-suff.size());
        // int m = suff.size();
        // int j = curr.size() - 1;
        // // while (m--) {
        // //     trail.push_back(j);
        // //     --j;
        // // }
        // reverse(trail.begin(), trail.end());
        int remaingLen = curr.size() - suff.size();

        long long c = 0;
        for (int i = 0; i < remaingLen; ++i) {
            int dig = curr[i] - '0';
            if (dig <= limit) {
                c += dig * powl(limit + 1, remaingLen - 1 - i);
            } else {
                c += powl(limit + 1, remaingLen - i);

                return c;
            }
        }

        if (trail >= suff)
            ++c;
        return c;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string end = to_string(finish);
        string strt = to_string(start - 1);

        return solve(end, s, limit) - solve(strt, s, limit);
    }
};