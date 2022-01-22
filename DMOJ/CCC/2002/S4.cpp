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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

struct segTree {
	int size;
	vector<long long> tree;

	void init(int n) {
		size = 1;
		while (size < n) size*=2;
		tree.assign(2*size, 0LL);
	}
	
	// has to be associative (a*b)*c == (a*c)*b
	long long func(long long x, long long y) {
		return max(x, y);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				tree[x] = a[lx];
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
			tree[x] = v;
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

	long long calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0; // IF CALC MIN, USE INT_MAX
		if (lx >= l && rx <= r) return tree[x];
		int mid = (lx + rx)/2;
		long long lChild = calc(l, r, 2*x+1, lx, mid);
		long long rChild = calc(l, r, 2*x+2, mid, rx);
		return func(lChild, rChild);
	}

	// calc within range
	long long calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
};
 
void solve() {
	// brute force is 20! = 2e18
	int m, q; cin >> m >> q;
	vs people(q);
	vi times(q);
	FOR (i, 0, q) cin >> people[i] >> times[i];

	// seg tree the max of groups
	segTree st;
	st.init(q);
	st.build(times);
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

