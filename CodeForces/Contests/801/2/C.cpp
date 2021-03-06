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
	// can move one square down or one square to the right at a time
	// brute force
	int n, m; cin >> n >> m;
	vector<vi> a(n, vi(m));
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cin >> a[i][j];
		}
	}
	vector<vector<set<int>>> vis(n, vector<set<int>>(m));
	queue<pair<int, int>> que;

	que.push(make_pair(0, 0));
	vis[0][0].ins(a[0][0]);

	while (!que.empty()) {
		pair<int, int> node = que.front();
		que.pop();

		int x = node.fir;
		int y = node.sec;

		if (x+1 < n) {
			bool ch=false;
			trav (i, vis[x][y]) {
				if (abs(a[x+1][y]+i) > n-x + m-y-1) {
					continue;
				}
				int ps=sz(vis[x+1][y]);
				vis[x+1][y].ins(a[x+1][y] + i);
				int ns=sz(vis[x+1][y]);
				if (ps!=ns) ch=true;

				if (x+1==n-1 && y==m-1 && a[x+1][y]+i == 0) {
					cout << "YES" << nl;
					return;
				}
			}
			if (ch) que.push(make_pair(x+1, y));
		}
		if (y+1 < m) {
			bool ch=false;
			trav (i, vis[x][y]) {
				if (abs(a[x][y+1]+i) > n-x + m-y-1) {
					continue;
				}
				int ps=sz(vis[x][y+1]);
				vis[x][y+1].ins(a[x][y+1] + i);
				int ns=sz(vis[x][y+1]);
				if (ps!=ns) ch=true;

				if (x==n-1 && y+1==m-1 && a[x][y+1]+i == 0) {
					cout << "YES" << nl;
					return;
				}
			}
			if (ch) que.push(make_pair(x, y+1));
		}
	}
	trav (i, vis[n-1][m-1]) {
		if (i == 0) {
			cout << "YES" << nl;
			return;
		}
	}
	cout << "NO" << nl;
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

