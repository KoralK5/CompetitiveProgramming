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

 
void solve() {
	int n, m; cin >> n >> m;
	vi c(n); FOR (i, 0, n) cin >> c[i];

	map<int, vi> graph;
	FOR (i, 0, m) {
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	// bfs for shortest dist to each color
	map<int, int> visLeft;
	queue<pi> que;
	que.push(mp(0, 1));
	visLeft[0] = 1;
	while (!que.empty()) {
		pi node = que.front();
		que.pop();

		int idx = node.fir;
		int cost = node.sec;

		trav (neigh, graph[idx]) {
			if (neigh == n-1) continue;
			if (visLeft[neigh] == 0 || visLeft[neigh] > cost+1) {
				visLeft[neigh] = cost+1;
				que.push(mp(neigh, cost+1));
			}
		}
	}
	
	map<int, int> visRight;
	queue<pi> que2;
	que2.push(mp(n-1, 1));
	visRight[n-1] = 1;
	while (!que2.empty()) {
		pi node = que2.front();
		que2.pop();

		int idx = node.fir;
		int cost = node.sec;

		trav (neigh, graph[idx]) {
			if (neigh == 0) continue;
			if (visRight[neigh] == 0 || visRight[neigh] > cost+1) {
				visRight[neigh] = cost+1;
				que2.push(mp(neigh, cost+1));
			}
		}
	}

	map<int, int> costLeft, costRight;
	FOR (i, 1, n+1) {
		costLeft[i] = 1e9;
		costRight[i] = 1e9;
	}

	trav (i, visLeft) {
		if (i.sec == 0) continue;
		ckmin(costLeft[c[i.fir]], i.sec-1);
	}
	trav (i, visRight) {
		if (i.sec == 0) continue;
		ckmin(costRight[c[i.fir]], i.sec-1);
	}

	int ans = 2e9;
	FOR (i, 1, n+1) {
		ckmin(ans, costLeft[i] + costRight[i]);
	}

	cout << (ans<1e9?ans:-1) << nl;
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

