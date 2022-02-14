/*
ID: Koral Kulacoglu
TASK: test
LANG: C++                 
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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
	unordered_map<int, int> recVis;
	recVis[a] = true;
	while (!que.empty()) {
		pi node = que.front(); que.pop();
		trav (neigh, h[node.fir]) {
			if (recVis[neigh] == 0) {
				recVis[neigh] = node.fir;

				if (neigh == c || neigh == d) {
					if (node.sec == 0) {
						que.push({neigh, 1});
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
		stk.push({recVis[node], node});
		node = recVis[node];
	}

	vi order(m, 2);

	// color the A-B path 1
	while (!stk.empty()) {
		pi node = stk.top(); stk.pop();
		order[mVals[node]] = 1;
		// cout << node.fir << ' ' << node.sec << nl;
	}

	int change = d;
	// color c
	if (cPath) change = c;
	// color d
	if (dPath) change = d;

	trav (i, h[change]) order[mVals[{change, i}]] = 1;
	
	cout << 2 << nl;
	trav (i, order) cout << i << nl;
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

