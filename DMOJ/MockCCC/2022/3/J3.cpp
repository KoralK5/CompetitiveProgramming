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
 
void solve() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	// make 2 frequency maps
	unordered_map<char, int> f1, f2;
	trav (i, s) f1[i]++;
	trav (i, t) f2[i]++;

	pair<char, int> ma1 = {' ', 0};
	pair<char, int> mi1 = {' ', 1e9};
	trav (i, f1) {
		int add = (i.sec+1)*(f2[i.fir]);
		int sub = (i.sec-1)*(f2[i.fir]);
		if (add > ma1.sec) {
			ma1.fir = i.fir;
			ma1.sec = add;
		}
		if (sub < mi1.sec && sub>=0) {
			mi1.fir = i.fir;
			mi1.sec = sub;
		}
	}

	pair<char, int> ma2 = {' ', 0};
	pair<char, int> mi2 = {' ', 1e9};
	trav (i, f2) {
		int add = (i.sec+1)*(f1[i.fir]);
		int sub = (i.sec-1)*(f1[i.fir]);
		if (add > ma2.sec) {
			ma2.fir = i.fir;
			ma2.sec = add;
		}
		if (sub < mi2.sec && sub>=0) {
			mi2.fir = i.fir;
			mi2.sec = sub;
		}
	}

	cout << ma1.fir << ' ' << mi1.fir ;
	cout << nl;
	cout << ma2.fir << ' ' << mi2.fir ;
	cout << nl;

	cout << ma1.sec << ' ' << mi1.sec ;
	cout << nl;
	cout << ma2.sec << ' ' << mi2.sec ;

	return;

	if (ma1.sec-mi2.sec > ma2.sec-mi1.sec) {
		f1[ma1.fir]++;
		f2[mi2.fir]--;
	}
	else {
		f2[mi2.fir]--;
		f1[ma2.fir]++;
	}
	int ans=0;
	trav (i, f1) {
		ans += i.sec*f2[i.fir];
	}
	cout << ans << nl;
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

