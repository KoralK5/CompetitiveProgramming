class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> friends;
        for (int i=0; i<n; i++) {
            friends.push_back({times[i][0], 1, i});
            friends.push_back({times[i][1], 0, i});
        }
        sort(friends.begin(), friends.end());
        unordered_map<int, int> friendIdx;
        int last = 0;
        vector<bool> chairs(n+1, false);
        for (auto& f : friends) {
            int t = f[0];
            int fr = f[2];
            if (fr == targetFriend) return last;
            auto it = friendIdx.find(fr);
            if (it == friendIdx.end()) {
                chairs[last] = true;
                friendIdx[fr] = last;
            }
            else {
                chairs[it->second] = false;
                last = min(last, it->second);
            }
            while (chairs[last]) last++;
        }
        return -1;
    }
};
