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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

struct segTree {
	int size;
	vector<vi> tree;

	void init(int n) {
		size = 1;
		while (size < n) size*=2;
		tree.resize(2*size, vi(3));
	}
	
	// has to be associative (a*b)*c == (a*c)*b
	vi func(vi x, vi y) {
		int comp = min(x[0], y[2]);
		return {x[0]+y[0]-comp, x[1]+y[1]+comp*2, x[2]+y[2]-comp};
	}

	void build(string a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				if (a[lx] == ')')
					tree[x] = {0, 0, 1};
				else
					tree[x] = {1, 0, 0};
			}
			return;
		}
		int mid = (lx + rx)/2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		tree[x] = func(tree[2*x+1], tree[2*x+2]);
	}

	void build(string a) {
		build(a, 0, 0, size);
	}

	void set(int i, char v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (v == ')')
				tree[x] = {0, 0, 1};
			else
				tree[x] = {1, 0, 0};
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
	void set(int i, char v) {
		set(i, v, 0, 0, size);
	}

	vi calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return {0, 0, 0}; // IF CALC MIN, USE INT_MAX
		if (lx >= l && rx <= r) return tree[x];
		int mid = (lx + rx)/2;
		vi lChild = calc(l, r, 2*x+1, lx, mid);
		vi rChild = calc(l, r, 2*x+2, mid, rx);
		return func(lChild, rChild);
	}

	// calc within range
	int calc(int l, int r) {
		return calc(l, r, 0, 0, size)[1];
	}
};
 
void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;

	segTree st;
	st.init(n);
	st.build(s);
	FOR (i, 0, q) {
		int qt; cin >> qt;
		if (qt == 1) {
			int l, r; cin >> l >> r;
			cout << st.calc(l-1, r) << nl;
		}
		else {
			int p; cin >> p; p--;
			char v = (s[p]==')'?'(':')');
			s[p] = v;
			st.set(p, v);
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

