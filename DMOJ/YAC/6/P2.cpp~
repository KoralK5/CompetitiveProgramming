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

// find the leaf node of each t
// go in order
// if A is in B, and t_i requires B to be in A, output -1

bool wk = true;
vi bossA, bossB;
vector<set<int>> empA, empB;
map<int, bool> vis;
vpi ans;

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;

	int boss = bossA[node];
	int nBoss = bossB[node];

	if (boss != nBoss) {
		ans.pb(mp(node, nBoss));

		bossA[node] = nBoss;
		empA[boss].erase(node);
		empA[nBoss].ins(node);
	}

	if (boss != -1) dfs(boss);
}

void solve() {
	int n, root=1; cin >> n;
	bossA.resize(n+1);
	bossB.resize(n+1);
	empA.resize(n+1);
	empB.resize(n+1);

	FOR (i, 1, n+1) {
		cin >> bossA[i];
		if (bossA[i] == -1) {
			root = i;
			continue;
		}

		empA[bossA[i]].ins(i);
	}

	int cnt = 0;
	FOR (i, 1, n+1) {
		cin >> bossB[i];
		if (bossB[i] == -1) {
			if (root != i) wk = false;
			continue;
		}

		empB[bossB[i]].ins(i);

		if (bossA[i] != bossB[i]) cnt++;
	}

	if (!wk) {
		cout << -1 << nl;
		return;
	}

	FOR (i, 1, n+1) {
		trav (j, empB[i]) {
			if (empB[j].find(i) != empB[j].end()) {
				cout << -1 << nl;
				return;
			}
		}
	}

	// start from the leaves
	set<int> leaves;
	// FOR (i, 1, n+1) leaves.ins(i);
	// FOR (i, 1, n+1) leaves.erase(bossA[i]);

	// trav (i, leaves) dfs(i);

	if (!wk) {
		cout << -1 << nl;
	}
	else {
		cout << cnt << nl;
		FOR (i, 0, cnt) cout << (root<n?root+1:root-1) << ' ' << root << nl;
		// cout << sz(ans) << nl;
		// trav (i, ans) cout << i.fir << ' ' << i.sec << nl;
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

