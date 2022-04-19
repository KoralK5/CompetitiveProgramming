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

const ll SZ = 1<<19;

template<class T> struct node {
	T val = 0; node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	void upd(ll ind, T v, ll L = 0, ll R = SZ-1) { // add v
		if (L == ind && R == ind) { val = v; return; }
		ll M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node();
			c[0]->upd(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->upd(ind,v,M+1,R);
		}
		val = 0; F0R(i,2) if (c[i]) val += c[i]->val;
	}
	T query(ll lo, ll hi, ll L = 0, ll R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return 0;
		if (lo <= L && R <= hi) return val;
		ll M = (L+R)/2; T res = 0;
		if (c[0]) res += c[0]->query(lo,hi,L,M);
		if (c[1]) res += c[1]->query(lo,hi,M+1,R);
		return res;
	}
};

template<class T> struct node1 {
	T val = 0; node1<T>* c[2];
	node1() { c[0] = c[1] = NULL; }
	void upd(ll ind, T v, ll L = 0, ll R = SZ-1) { // add v
		if (L == ind && R == ind) { val = v; return; }
		ll M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node1();
			c[0]->upd(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node1();
			c[1]->upd(ind,v,M+1,R);
		}
		val = 0; F0R(i,2) if (c[i]) val = max(val, c[i]->val);
	}
	T query(ll lo, ll hi, ll L = 0, ll R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return 0;
		if (lo <= L && R <= hi) return val;
		ll M = (L+R)/2; T res = 0;
		if (c[0]) res = max(res, c[0]->query(lo,hi,L,M));
		if (c[1]) res = max(res, c[1]->query(lo,hi,M+1,R));
		return res;
	}
};

void solve() {
	ll n, q, ans=0; cin >> n >> q;
	node<ll> stS;
	node1<ll> stM;
	FOR (i, 0, q) {
		char qt; cin >> qt;
		if (qt == 'C') {
			ll x, v; cin >> x >> v;
			// cout << (x^ans) << ' ' << (v^ans) << nl;
			stS.upd(x^ans, v^ans);
			stM.upd(x^ans, v^ans);
		}
		else if (qt == 'S') {
			ll l, r; cin >> l >> r;
			// cout << (l^ans) << ' ' << (r^ans) << nl;
			ans = stS.query(l^ans, (r^ans)+1);
			cout << ans << nl;
		}
		else {
			ll l, r; cin >> l >> r;
			// cout << (l^ans) << ' ' << (r^ans) << nl;
			ans = stM.query(l^ans, (r^ans)+1);
			cout << ans << nl;
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

