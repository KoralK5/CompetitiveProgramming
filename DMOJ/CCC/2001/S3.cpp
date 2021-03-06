#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, vector<char>> road;
vector<char> visited;

bool bfs(char node, string no) {
	vector<char> queue;
	queue.push_back(node);
	visited.push_back(node);
	while (queue.size()!=0) {
		node = queue.back();
		queue.pop_back();
		for (char curr : road[node]) {
			if (!((node==no[0] && curr==no[1]) || (node==no[1] && curr==no[0])) && find(visited.begin(), visited.end(), curr) == visited.end()) {
				visited.push_back(curr);
				queue.push_back(curr);
				if (curr=='A') return true; 
			}
		}
	}
	return false;
}
		
int main() {
	string val;
	vector<string> con;
	while (true) {
		cin>>val;
		if (val == "**") break;
		con.push_back(val);
		road[val[0]].push_back(val[1]);
		road[val[1]].push_back(val[0]);
	}
	int ans=0;
	for (string cu: con) {
		if (!bfs('B', cu)) {
			cout<<cu[0]<<cu[1]<<endl;
			ans++;
		}
		visited.clear();
	}
	cout<<"There are "<<ans<<" disconnecting roads.\n";
}
