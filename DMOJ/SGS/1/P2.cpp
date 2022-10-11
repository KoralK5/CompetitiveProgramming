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

// a[i] > a[j]?
bool q1(int i, int j) {
	cout << "? " << i << ' ' << j << endl;
	bool gt; cin >> gt;
	return gt;
}

// v is indices, returns index of xth rank
int q2(set<int> v, int x) {
	cout << "$ " << sz(v) << ' ';
	trav (i, v) cout << i << ' ';
	cout << x << endl;
	int y; cin >> y;
	return y;
}

// rank of a number as the number of numbers smaller than it in the array
//
// binary search:
// 		find 2^16						m queries
// 			remove all smaller ranks	m queries
// 		find 2^15						<m queries
// 			remove all smaller ranks	<m queries
// 		find 2^14						<m queries
// 			remove all smaller ranks	<m queries
// 		...
// 		find 2^0						~0 queries
// 			remove all smaller ranks

void solve() {
	int n; cin >> n;

	int twos = 0;
	FOR (i, 0, 32) {
		if (pow(2, i) >= n) {
			twos = i-1;
			break;
		}
	}

	vi ans;
	set<int> idxs; FOR (i, 0, n) idxs.ins(i);

	FORd (i, twos+1, 0) {
		int rank = pow(2, i);
		int idx = q2(idxs, rank);

		/*
		int idx = 0;
		trav (i, idxs) {
			if (!temp) {
				idx = i;
				break;
			}
			temp--;
		}
		*/

		ans.pb(idx);

		set<int> nIdxs;
		trav (i, idxs) {
			if (idx == i) continue;
			bool gt = q1(idx, i);
			if (gt) nIdxs.ins(i);
		}

		idxs = nIdxs;
	}

	reverse(all(ans));
	cout << "! " << twos << ' ';
	trav (i, ans) cout << i << ' ';
	cout << nl;
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

