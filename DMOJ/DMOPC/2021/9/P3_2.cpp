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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fir); cerr << ","; _print(p.sec); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << "| " << #x << " = "; _print(x); cerr << " |" << endl;
#else
#define dbg(x)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

void print(vector<vi> a) {
	trav (i, a) {
		trav (j, i) {
			cout << j << ' ';
		}
		cout << nl;
	}
	cout << nl;
}

void solve() {
	unordered_map<int, vi> graph;
	vector<vi> dists;
	int n, m; cin >> n >> m;
	FOR (i, 0, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	// precompute all distances for subtask 1
	// O(1e6)
	dists.resize(n, vi(n, 1e9));
	unordered_map<int, bool> vis;
	trav (i, graph) {
		vis.clear();
		queue<pi> que;
		que.push({i.fir, 0});
		while (!que.empty()) {
			pi cur = que.front(); que.pop();
			int node=cur.fir, dist=cur.sec;
			dists[i.fir][node] = dist;
			vis[node] = true;
			trav (neigh, graph[node]) {
				if (vis[neigh]) continue;
				que.push({neigh, dist+1});
			}
		}
	}
	// print(dists);

	int q; cin >> q;
	FOR (i, 0, q) {
		int s, t, x, u, v, y; cin >> s >> t >> x >> u >> v >> y;
		s--; t--; u--; v--;
		
		if (dists[s][t] <= x || dists[u][v] <= y) {
		    cout << "YES" << nl;
		}
		else if ((ll)dists[s][u] + 1 + dists[t][v] + 1 <= x+y) {
			cout << "YES" << nl;
		}
		else if ((ll)dists[s][v] + 1 + dists[t][u] + 1 <= x+y) {
			cout << "YES" << nl;
		}
		else {
		    cout << "NO" << nl;
		}
	}
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
