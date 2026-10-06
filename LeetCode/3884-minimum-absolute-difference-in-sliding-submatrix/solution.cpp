class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n-k+1, vector<int>(m-k+1, 0));
        if (k == 1) return res;
        for (int i=0; i<=n-k; i++) {
            for (int j=0; j<=m-k; j++) {
                set<int> vals;
                for (int l=0; l<k; l++) {
                    for (int c=0; c<k; c++) {
                        vals.insert(grid[i+l][j+c]);
                    }
                }
                int mn = 1e9;
                int l = vals.size();
                if (l == 1) {
                    res[i][j] = 0;
                    continue;
                }
                int prev = -1e9;
                for (int i : vals) mn = min(mn, - prev + (prev = i));
                res[i][j] = mn;
            }
        }
        return res;
    }
};
