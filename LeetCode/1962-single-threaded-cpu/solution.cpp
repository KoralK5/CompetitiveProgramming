class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i=0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // processing time, index
        long long curTime;
        int i = 0;
        while (i < n) {
            curTime = tasks[i][0];
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
            while (!pq.empty()) {
                auto [t, idx] = pq.top();
                pq.pop();
                res.push_back(idx);
                curTime += t;
                while (i < n && tasks[i][0] <= curTime) {
                    pq.push({tasks[i][1], tasks[i][2]});
                    i++;
                }
            }
        }
        return res;
    }
};
