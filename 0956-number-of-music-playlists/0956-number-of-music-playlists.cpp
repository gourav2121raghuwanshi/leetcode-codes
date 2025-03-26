class Solution {
    const int mod = 1e9 + 7;
    int N, K, Goal;
    int dp[101][101];
    int solve(int total_played, int unique_played) {
        if (total_played == Goal)
            return N == unique_played;

        if (dp[total_played][unique_played] != -1)
            return dp[total_played][unique_played];
        // unique Not played = (n-unique_already_played)
        int playUnique = 0;
        if (N > unique_played)
            playUnique = ((N - unique_played) * 1LL *
                          solve(total_played + 1, unique_played + 1)) %
                         mod;
        int repeat = 0;
        if (unique_played > K)
            repeat = ((unique_played - K) * 1LL *
                      solve(total_played + 1, unique_played)) %
                     mod;

        return dp[total_played][unique_played] = (playUnique + repeat) % mod;
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        N = n;
        K = k;
        Goal = goal;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0); // total_played_songs, total_unique_songs
    }
};