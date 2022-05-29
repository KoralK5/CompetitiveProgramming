void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for (int i=0; i<N; i++) dist[i] = INF;
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		pair<int, int> front = pq.top();
		pq.pop();
		int w = front.first, u = front.second;
		if (w > dist[u]) continue;
		for (int i=0; i<adj[u].size(); i++) {
			pair<int, int> v = adj[u][i];
			if (dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
				pq.push(make_pair(dist[v.first], v.first));
			}
		}
	}
}
