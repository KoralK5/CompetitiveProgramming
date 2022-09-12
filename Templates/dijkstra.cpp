unordered_map<int, vector<pair<int, int>>> graph;

void addEdge(int u, int v, int dist) {
    graph[u].push_back(make_pair(v, dist));
}

int startDijkstra(int u, int end) {
    vector<int> dist(1e5, 1e9);

    set<pair<int, int> > st;
    st.insert(make_pair(0, u));
    dist[u] = 0;

    while (!st.egraphty()) {
        pair<int, int> now = *st.begin();
        st.erase(st.begin());

        int v = now.second;
        int w = now.first;

        const vector<pair<int, int> > &edges = graph[v];
        for (const pair<int, int> &to : edges) {
            if (w + to.second < dist[to.first]) {
                st.erase(make_pair(dist[to.first], to.first));
                dist[to.first] = w + to.second;
                st.insert(make_pair(dist[to.first], to.first));
            }
        }
    }

    return dist[end];
}

// distance from start to end
int solve(vector<vector<int>>& edges, int start, int end) {
    graph.clear();
    for (vector<int> &edge : edges) {
        addEdge(edge[0], edge[1], edge[2]);
    }
    int res = startDijkstra(start, end);
    return res<1e9?res:-1;
}
