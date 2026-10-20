struct DSU {
    int n;
    vector<int> parent, sizes;

    DSU(int n) : n(n), parent(n), sizes(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        int sx = sizes[px];
        int sy = sizes[py];

        if (sizes[px] > sizes[py]) swap(px, py);

        parent[px] = py;
        sizes[py] += sizes[px];
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, vector<int>> accMap;
        for (int i=0; i<n; i++) {
            auto& a = accounts[i];
            int m = a.size();
            for (int j=1; j<m; j++) {
                accMap[a[j]].push_back(i);
            }
        }
        for (auto& a : accMap) {
            int m = a.second.size();
            int prev = a.second[0];
            for (int i=1; i<m; i++) {
                int cur = a.second[i];
                dsu.unite(prev, cur);
                cout << prev << ' ' << cur << endl;
                prev = cur;
            }
        }
        unordered_map<int, pair<string, set<string>>> mp;
        for (int i=0; i<n; i++) {
            int p = dsu.find(i);
            int m = accounts[i].size();
            string name = accounts[i][0];
            mp[p].first = name;
            for (int j=1; j<m; j++) mp[p].second.insert(accounts[i][j]);
        }
        int i=0;
        vector<vector<string>> res;
        for (auto [id, p] : mp) {
            res.push_back({});
            res[i].push_back(p.first);
            for (auto v : p.second) res[i].push_back(v);
            i++;
        }
        return res;
    }
};
