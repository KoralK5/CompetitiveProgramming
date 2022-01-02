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
#define gcd(a, b) __gcd(a, b)
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

map<int, int> gcdFreqs;

void gcds(int n) {
    for (int i=1; i<=sqrt(n); i++) {
        if (n%i == 0) {
			gcdFreqs[i]++;
            if (n/i != i)
				gcdFreqs[n/i]++;
        }
    }
}

void solve() {
	int n; cin >> n;
	// each idx, update gcd with difference
	int curr, prev=1e6+1;
	bool same=true;
	FOR (i, 0, n) {
		cin >> curr;
		gcds(abs(curr));
		if (prev!=curr) same=false;
		prev = curr;
	}
	if (same) {
		cout << -1 << nl;
		return;
	}
	
	trav(i, gcdFreqs) {
		cout << i.fir << " " << i.sec << nl;
	}
	cout << "CASE" << nl;
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

