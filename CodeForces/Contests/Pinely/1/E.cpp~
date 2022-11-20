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
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define F0Rd(i, a) for (int i=(a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef DEBUG
#define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << endl;
#else
#define dbg(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= rng();
        return x ^ (x >> 16);
    }
};
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

// each time a node is operated on, it becomes part of every node its not in
// when one node is operated on, everything is connected except for its neighbors
// if its neighbors are connected to a node it's not connected to, then 1 operation is enough
// find the minimum cycle where everything is connected to everything else??
// 		if there's a cycle without this, then use one operation on that
// 		if there's an isolated vertex, operate on that
 
map<int, vi> graph;
map<int, bool> used;
set<int> seen;

void allCon(int node) {
	if (used[node]) return;
	seen.ins(node);
	used[node] = true;

	trav (neigh, graph[node]) {
		allCon(neigh);
	}
}

int cycCon(int node) {
	set<int> vals;
	vals.ins(node);
	trav (i, graph[node]) vals.ins(i);

	trav (i, graph[node]) {
		set<int> vals2;
		vals2.ins(i);
		trav (j, graph[i]) vals2.ins(j);
 
		if (vals != vals2) return i;
	}
	return -1;
}

void solve() {
	used.clear();
	seen.clear();
	graph.clear();

	int n; cin >> n;
	FOR (i, 0, n) {
		string s; cin >> s;
		FOR (j, 0, n) {
			if (s[j] == '1') graph[i].pb(j);
		}
	}

	allCon(1);
	if (sz(seen) == n) {
		cout << 0 << nl;
		return;
	}

	FOR (i, 0, n) {
		if (graph[i].empty()) {
			cout << 1 << nl;
			cout << i+1 << nl;
			return;
		}
	}

	// find a component where every vertex isn't connected to others
	FOR (i, 0, n) {
		int res = cycCon(i);
		if (res != -1) {
			cout << 1 << nl;
			cout << res+1 << nl;
			return;
		}
	}

	// now every cycle is connected to each other
	int best=1e9, idx=0;
	FOR (i, 0, n) {
		if (sz(graph[i]) < best) {
			best = sz(graph[i]);
			idx = i;
		}
	}

	cout << best+1 << nl;
	cout << idx+1 << ' ';
	trav (i, graph[idx]) cout << i+1 << ' ';
	cout << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

