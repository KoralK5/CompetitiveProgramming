#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
typedef pair<int, int> pi;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define ins insert
#define lbound(a, v) lower_bound(all(a), v)-a.begin()
#define ubound(a, v) upper_bound(all(a), v)-a.begin()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/gcd(a, b)
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int n, m, a, b, c, d;
unordered_map<int, vi> h;

// dfs to see if there is a path between A and D that does not visit C and D
// if all paths from A-B covers C and D, -1
// make C visited, then D visited
unordered_map<int, bool> visited;
bool dfs(int node) {
	if (node == b) return true;

	if (!visited[node]) {
		visited[node] = true;
		trav (neigh, h[node]) {
			if (dfs(neigh)) {
				return true;
			}
		}
	}

	return false;
}

void solve() {
	// use maximum 2 colors (don't care about C to D)
	// A to B is the same color
	cin >> n >> m;
	map<pi, int> mVals;
	FOR (i, 0, m) {
		int a, b; cin >> a >> b;
		h[a].pb(b);
		h[b].pb(a);
		mVals[{a, b}] = i;
		mVals[{b, a}] = i;
	}

	cin >> a >> b >> c >> d;
	if (find(all(h[c]), d) != h[c].end()) {
		cout << -1 << nl;
		return;
	}

	// whichever does not work
	visited[c] = true;
	bool cPath = dfs(a);

	visited.clear();
	visited[d] = true;
	bool dPath = dfs(a);

	if (!cPath && !dPath) {
		cout << -1 << nl;
		return;
	}

	// now we know it must work
	// bfs from A to B (can use just 2 colors)
	// reconstruct by keeping track of each parent node in the neighbor
	queue<pair<int, bool>> que;
	que.push({a, false});
	unordered_map<int, int> rVis;
	rVis[a] = true;
	while (!que.empty()) {
		pi node = que.front(); que.pop();
		trav (neigh, h[node.fir]) {
			if (rVis[neigh] == 0) {
				rVis[neigh] = node.fir;

				if (neigh == c || neigh == d) {
					if (node.sec == 0) {
						que.push({neigh, 1});
					}
					// go back to C or D and make everything not visited
					// make C visited?
					// THIS CASE SHOULD NOT OCCUR!
					// assert(false)
					else {
						// cout << "CASE" << nl;
						int curNode = neigh;
						int chNode = neigh==c?d:c;
						while (curNode != chNode) {
							int temp = rVis[curNode];
							// this is problematic
							rVis[curNode] = 0;
							curNode = temp;
						}
					}
				}
				else {
					que.push({neigh, 0});
				}
			}
			if (neigh == b) {
				break;
			}
		}
	}

	stack<pi> stk;
	int node = b;
	while (node != a) {
		stk.push({rVis[node], node});
		node = rVis[node];
	}

	vi order(m, 2);

	// color the A-B path 1
	bool dSeen=false;
	while (!stk.empty()) {
		pi node = stk.top(); stk.pop();
		order[mVals[node]] = 1;
		if (node.fir == d || node.sec == d) dSeen = true;
		// cout << node.fir << ' ' << node.sec << nl;
	}

	int change = c;
	if (dSeen) change = d;

	trav (i, h[change]) order[mVals[{change, i}]] = 1;
	
	cout << 2 << nl;
	trav (i, order) cout << i << nl;

	// change the color based on which one does not work
	// if the best path crosses C or D, make them all 1s
	/*
	int change = c;
	if (!cPath) change = d;
	if (!dPath) change = c;
	*/
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

