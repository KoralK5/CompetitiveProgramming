#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
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
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define lbound lower_bound
#define ubound upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/gcd(a, b)
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

struct segTree {
	int size;
	vector<vll> tree;

	void init(int n) {
		size = 1;
		while (size < n) size*=2;
		tree.assign(2*size, vll(4, 0LL));
	}
	
	// has to be associative (a*b)*c == (a*c)*b
	// seg  = max(seg1, seg2, suf1+pref2)
	// pref = max(pref1, sum1+pref2)
	// suf  = max(suf2, sum2+suf2)
	// sum  = sum1 + sum2
	// seg, pref, suf, sum
	vll func(vll x, vll y) {
		ll seg  = max(x[0], max(y[0], x[2]+y[1]));
		ll pref = max(x[1], x[3]+y[1]);
		ll suf  = max(y[2], y[3]+x[2]);
		ll sum  = x[3]+y[3];
		return {seg, pref, suf, sum};
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				tree[x] = {a[lx], a[lx], a[lx], a[lx]};
			}
			return;
		}
		int mid = (lx + rx)/2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		tree[x] = func(tree[2*x+1], tree[2*x+2]);
	}

	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = {v, v, v, v};
			return;
		}
		int mid = (lx + rx)/2;
		if (i < mid) {
			set(i, v, 2*x+1, lx, mid);
		}
		else {
			set(i, v, 2*x+2, mid, rx);
		}
		tree[x] = func(tree[2*x+1], tree[2*x+2]);
	}

	// i:index, v:value
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	vll calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return {0, 0, 0, 0}; // IF CALC MIN, USE INT_MAX
		if (lx >= l && rx <= r) return tree[x];
		int mid = (lx + rx)/2;
		vll lChild = calc(l, r, 2*x+1, lx, mid);
		vll rChild = calc(l, r, 2*x+2, mid, rx);
		return func(lChild, rChild);
	}

	// calc within range
	vll calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
};
 
void solve() {
	int n, m; cin >> n >> m;
	vi a;
	FOR (i, 0, n) cin >> a[i];
	segTree st;
	st.init(n);
	st.build(a);
	int i, v;
	FOR (j, 0, m) {
		cin >> i >> v;
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

