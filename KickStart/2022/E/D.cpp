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

char northOp;
ll north;

char eastOp;
ll east;

char westOp;
ll west;

char southOp;
ll south;

int n, p, m, r, c; 

ll goNorth(ll coins) {
	if (northOp=='+') return coins+north;
	if (northOp=='-') return coins-north;
	if (northOp=='*') return coins*north;
	if (northOp=='/') return floor((double)coins/north);
	return coins;
}

ll goSouth(ll coins) {
	if (southOp=='+') return coins+south;
	if (southOp=='-') return coins-south;
	if (southOp=='*') return coins*south;
	if (southOp=='/') return floor((double)coins/south);
	return coins;
}

ll goEast(ll coins) {
	if (eastOp=='+') return coins+east;
	if (eastOp=='-') return coins-east;
	if (eastOp=='*') return coins*east;
	if (eastOp=='/') return floor((double)coins/east);
	return coins;
}

ll goWest(ll coins) {
	if (westOp=='+') return coins+west;
	if (westOp=='-') return coins-west;
	if (westOp=='*') return coins*west;
	if (westOp=='/') return floor((double)coins/west);
	return coins;
}

vector<vector<vector<vll>>> dp; // time, x, y, pizza remaining, money
map<pi, ll> pizzas;
map<pi, int> idxs;

ll dfs(int x, int y, int time, int pizza, ll coins) {
	int val = idxs[mp(x, y)];
	if (val && ((pizza>>(val-1)) & 1)) {
		pizza &= ~(1<<(val-1));
		coins += pizzas[mp(x, y)];
	}

	if (coins <= dp[time][x][y][pizza]) return dp[time][x][y][pizza];

	ckmax(dp[time][x][y][pizza], coins);
	if (time >= m) return coins;

	ll best = dfs(x, y, time+1, pizza, coins);
	if (x+1 <= n) {
		ckmax(best, dfs(x+1, y, time+1, pizza, goSouth(coins)));
	}
	if (y+1 <= n) {
		ckmax(best, dfs(x, y+1, time+1, pizza, goEast(coins)));
	}
	if (x-1 > 0) {
		ckmax(best, dfs(x-1, y, time+1, pizza, goNorth(coins)));
	}
	if (y-1 > 0) {
		ckmax(best, dfs(x, y-1, time+1, pizza, goWest(coins)));
	}
	
	return best;
}

void print(auto a) {
	cout << nl;
	trav (i, a) {
		trav (j, i) {
			trav (k, j) {
				if (k[0] > -1e9) cout << k[0] << ' ';
				else cout << 'x' << ' ';
			}
			cout << nl;
		}
		cout << nl;
	}
	cout << nl;
}
 
void solve() {
	cin >> n >> p >> m >> r >> c;

	pizzas.clear();
	idxs.clear();
	dp.clear();
	dp.resize(m+1, vector<vector<vll>>(n+1, vector<vll>(n+1, vll(pow(2, p), -1e9))));

	cin >> northOp;
	cin >> north;

	cin >> eastOp;
	cin >> east;

	cin >> westOp;
	cin >> west;

	cin >> southOp;
	cin >> south;

	FOR (i, 0, p) {
		int x, y; cin >> x >> y;
		ll ci; cin >> ci;
		pizzas[mp(x, y)] = ci;
		idxs[mp(x, y)] = i+1;
	}

	dfs(r, c, 0, pow(2, p)-1, 0);

	ll ans = -1e9;
	trav (i, dp[m]) {
		trav (j, i) {
			ckmax(ans, j[0]);
		}
	}

	// print(dp);

	if (ans > -1e9) cout << ans << nl;
	else cout << "IMPOSSIBLE" << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

	int T = 1;
	cin >> T;
	FOR (i, 1, T+1) {
		cout << "Case #" << i << ": ";
        solve();
    }
 
	return 0;
}

