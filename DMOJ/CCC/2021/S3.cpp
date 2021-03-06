/*
ID: Koral Kulacoglu
TASK: https://dmoj.ca/problem/ccc21s3
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

int n;
vector<vi> arr;
ll cost(ll loc) {
	ll res=0;
	FOR (i, 0, n) {
		ll p=arr[i][0], w=arr[i][1], d=arr[i][2];
		// find meters left
		ll m = abs(loc - p) - d;
		if (m > 0) {
			res += m*w;
		}
	}
	return res;
}
 
void solve() {
	cin >> n;
	int p, w, d, l=1e9, r=0;
	FOR (i, 0, n) {
		cin >> p >> w >> d;
		arr.pb({p,w,d});
		l = min(l, p);
		r = max(r, p);
	}
	/*
	ll ans=1e14;
	FOR (i, mi, ma+1) {
		ans = min(ans, cost(i));
	}
	cout << ans;
	*/

	// binary search min cost
	// store precalculated
	unordered_map<ll, ll> seen;
	ll cm, cr, cl;
    while (l <= r) {
        ll mid = (l+r)/2;
		cm = seen[mid]?seen[mid]:cost(mid);
		cl = seen[mid-1]?seen[mid-1]:cost(mid-1);
		cr = seen[mid+1]?seen[mid+1]:cost(mid+1);
		seen[mid] = cm;
		seen[mid-1] = cl;
		seen[mid+1] = cr;
        if ((cm < cr && cm < cl) || (cl==cr)) {
			cout << cm;
			return;
		}
        if (cl > cr) {
			l = mid+1;
		}
		else {
			r = mid-1;
		}
	} 
	cout << cm;
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

