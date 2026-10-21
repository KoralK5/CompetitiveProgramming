class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) return -1;
        // job index, day, max of current day
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(d, vector<int>(1001, 1e9)));
        dp[0][0][jobDifficulty[0]] = jobDifficulty[0];
        for (int i=1; i<n; i++) {
            for (int j=0; j<d; j++) {
                for (int k=0; k<=1000; k++) {
                    int extra = max(0, jobDifficulty[i] - k);
                    dp[i][j][k + extra] = min(dp[i][j][k + extra], dp[i-1][j][k] + extra);
                    if (j > 0) dp[i][j][jobDifficulty[i]] = min(dp[i][j][jobDifficulty[i]], dp[i-1][j-1][k] + jobDifficulty[i]);
                }
            }
        }
        int res = *min_element(dp[n-1][d-1].begin(), dp[n-1][d-1].end());
        return res < 1e9 ? res : -1;
    }
};
