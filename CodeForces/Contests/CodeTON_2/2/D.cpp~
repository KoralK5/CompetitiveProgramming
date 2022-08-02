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

// 2 operation 1s can form an operation 2 - left index
// on the left side, operation 1 has left increase, right decrease
// 					 operation 2 has 2 left increase, 2 right decrease
//
// the rightmost operation 2 must have a different property
// it's 3-delta 

/*
5 5 5

4 6 5
4 5 6

4 5 6
*/
 
void solve() {
	int n, m; cin >> n >> m;
	vector<vll> c(n, vll(m));
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cin >> c[i][j];
		}
	}
	vector<vll> dt(n, vll(m));
	FOR (i, 0, n) dt[i][0] = c[i][0] - c[0][0];
	FOR (i, 0, n) {
		FOR (j, 1, m) {
			dt[i][j] = dt[i][j-1] + c[i][j] - c[0][j];
		}
	}
	// delta difference is somehow magically the answer
	FOR (i, 0, n) {
		set<ll> vals;
		FOR (j, 0, m) {
			if (dt[i][j] != 0) vals.ins(dt[i][j]);
		}
		if (sz(vals) == 1) {
			ll cnt = accumulate(all(dt[i]), 0);
			cout << i+1 << ' ' << -cnt << nl;
			return;
		}
	}

	dt.clear();
	dt.resize(n, vll(m));
	FOR (i, 0, n) dt[i][0] = c[i][0] - c[1][0];
	FOR (i, 0, n) {
		FOR (j, 1, m) {
			dt[i][j] = dt[i][j-1] + c[i][j] - c[1][j];
		}
	}
	// delta difference is somehow magically the answer
	FOR (i, 0, n) {
		set<ll> vals;
		FOR (j, 0, m) {
			if (dt[i][j] != 0) vals.ins(dt[i][j]);
		}
		if (sz(vals) == 1) {
			ll cnt = accumulate(all(dt[i]), 0);
			cout << i+1 << ' ' << -cnt << nl;
			return;
		}
	}

	vector<vll> ndt(n, vll(m));
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			FOR (k, 0, n) {
				ndt[i][j] += c[k][j] - c[i][j];
			}
		}
	}
	vll cost(n, 0);
	FOR (i, 0, n) {
		ll score = 0;
		FOR (j, 0, m) {
			score += ndt[i][j];
		}
		FOR (j, 0, m) {
			if ((score<0) != (dt[i][j]<0)) {
				cost[i]++;
			}
		}
	}
	int idx = max_element(all(cost)) - cost.begin();
	ll cnt = accumulate(all(dt[idx]), 0);
	cout << idx+1 << ' ' << -cnt << nl;
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

