/*
id: koral kulacoglu
task: test
lang: c++                 
*/

#pragma gcc optimize ("o3")
#pragma gcc target ("sse4")
 
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

template<class t> using pq = priority_queue<t>;
template<class t> using pqg = priority_queue<t, vector<t>, greater<t>>;
 
#define for(i, a, b) for (int i=a; i<(b); i++)
#define f0r(i, a) for (int i=0; i<(a); i++)
#define ford(i,a,b) for (int i = (b)-1; i >= a; i--)
#define f0rd(i,a) for (int i = (a)-1; i >= 0; i--)
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
 
template<class t> bool ckmin(t& a, const t& b) { return b < a ? a = b, 1 : 0; }
template<class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, 1 : 0; }

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class t, class v> void _print(pair <t, v> p);
template <class t> void _print(vector <t> v);
template <class t> void _print(set <t> v);
template <class t, class v> void _print(map <t, v> v);
template <class t> void _print(multiset <t> v);
template <class t, class v> void _print(pair <t, v> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class t> void _print(vector <t> v) {cerr << "[ "; for (t i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class t> void _print(set <t> v) {cerr << "[ "; for (t i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class t> void _print(multiset <t> v) {cerr << "[ "; for (t i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class t, class v> void _print(map <t, v> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef online_judge
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int mod = 1000000007;
const char nl = '\n';
const int mx = 100001; 

int n, m, a, b, c, d;
unordered_map<int, vi> h;

// dfs to see if there is a path between a and d that does not visit c and d
// if all paths from a-b covers c and d, -1
// make c visited, then d visited
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
	// use maximum 2 colors (don't care about c to d)
	// a to b is the same color
	cin >> n >> m;
	map<pi, int> mvals;
	for (i, 0, m) {
		int a, b; cin >> a >> b;
		h[a].pb(b);
		h[b].pb(a);
		mvals[{a, b}] = i;
		mvals[{b, a}] = i;
	}

	cin >> a >> b >> c >> d;
	if (find(all(h[c]), d) != h[c].end()) {
		cout << -1 << nl;
		return;
	}

	// whichever does not work
	visited[c] = true;
	bool cpath = dfs(a);

	visited.clear();
	visited[d] = true;
	bool dpath = dfs(a);

	if (!cpath && !dpath) {
		cout << -1 << nl;
		return;
	}

	// now we know it must work
	// bfs from a to b (can use just 2 colors)
	// reconstruct by keeping track of each parent node in the neighbor
	queue<pair<int, bool>> que;
	que.push({a, false});
	unordered_map<int, int> recvis;
	recvis[a] = true;
	while (!que.empty()) {
		pi node = que.front(); que.pop();
		trav (neigh, h[node.fir]) {
			if (recvis[neigh] == 0) {
				recvis[neigh] = node.fir;

				if (neigh == c || neigh == d) {
					if (node.sec == 0) {
						que.push({neigh, 1});
					}
					// go back to c or d and make everything not visited
					// make c visited?
					// this case should not occur!
					else {
						// cout << "case" << nl;
						int curnode = neigh;
						int chnode = neigh==c?d:c;
						while (curnode != chnode) {
							int temp = recvis[curnode];
							recvis[curnode] = 0;
							curnode = temp;
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
		stk.push({recvis[node], node});
		node = recvis[node];
	}

	vi order(m, 2);

	// color the a-b path 1
	while (!stk.empty()) {
		pi node = stk.top(); stk.pop();
		order[mvals[node]] = 1;
		// cout << node.fir << ' ' << node.sec << nl;
	}

	// change the color based on which one does not work
	int change = c;
	if (!cpath) change = d;
	if (!dpath) change = c;

	trav (i, h[change]) order[mvals[{change, i}]] = 1;
	
	cout << 2 << nl;
	trav (i, order) cout << i << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int t = 1;
//    cin >> t;
    while(t--) {
        solve();
    }
 
	return 0;
}
