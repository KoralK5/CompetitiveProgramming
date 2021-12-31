#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
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
	
	long long operation(long long x, long long y) {
		return x + y;
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
		tree[x] = operation(tree[2*x+1], tree[2*x+2]);
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
		tree[x] = operation(tree[2*x+1], tree[2*x+2]);
	}

	// i:index, v:value
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	long long calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return tree[x];
		int mid = (lx + rx)/2;
		long long lChild= calc(l, r, 2*x+1, lx, mid);
		long long rChild = calc(l, r, 2*x+2, mid, rx);
		return operation(lChild, rChild);
	}

	// calc within range
	long long calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
};
 
void solve() {
	int n, m; cin >> n >> m;
	vi a(n);
	segTree st;
	st.init(n);

	FOR (i, 0, n) {
		cin >> a[i];
	}
	st.build(a);

	int op, i, v, l, r;
	FOR (j, 0, m) {
		cin >> op;
		if (op == 1) {
			cin >> i >> v;
			st.set(i, v);
		}
		else {
			cin >> l >> r;
			cout << st.calc(l, r) << nl;
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

