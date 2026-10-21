class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> costs(n, vector<vector<int>>(m, vector<int>(k+1, 1e9)));
        costs[0][0][0] = 0;
        queue<tuple<int, int, int, int>> que; // x, y, k, cost
        que.push({0, 0, 0, 0});
        while (!que.empty()) {
            auto [x, y, c, cost] = que.front();
            que.pop();

            if (costs[x][y][c] < cost) continue;

            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int newC = c + grid[nx][ny];
                if (newC > k) continue;

                int newCost = cost + 1;
                if (costs[nx][ny][newC] <= newCost) continue;

                costs[nx][ny][newC] = newCost;
                que.push({nx, ny, newC, newCost});
            }
        }

        int res = *min_element(costs[n-1][m-1].begin(), costs[n-1][m-1].end());

        return res < 1e9 ? res : -1;
    }
};
