#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, vector<int>> tree;
vector<int> pho;
int dist=0;

int bfs(int node) {
	vector<int> queue;
	vector<int> visited;
	
	visited.push_back(node);
	queue.push_back(node);
	int count=0;
	while (queue.size()!=0) {
		node = queue.front();
		queue.erase(queue.begin());
		count++;
		for (int i : tree[node]) {
			auto idx = find(pho.begin(), pho.end(), i);
			if (idx != pho.end()) {
				int d = distance(pho.begin(), idx);
				int temp = pho[d];
				pho.erase(pho.begin() + d);
				return temp; 
			}
			if (find(visited.begin(), visited.end(), i) != visited.end()) {
				visited.push_back(i);
				queue.push_back(i);
			}
		}
	}
}	

int main() {
	int n,m,cr;
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		cin>>cr;
		pho.push_back(cr);
	}

	int k,v;
	for (int i=0; i<n; i++) {
		cin>>k>>v;
		tree[k].push_back(v);
		tree[v].push_back(k);
	}

	int loc=0;
	for (int i=0; i<m; i++) {
		loc = bfs(loc);
	}
	cout<<dist;
}
