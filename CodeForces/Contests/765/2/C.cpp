/*
ID: Koral Kulacoglu
TASK: https://codeforces.com/contest/1625/problem/C
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
	int n, l, k; cin >> n >> l >> k;
	vi sign(n+1), speed(n+1);
	FOR (i, 0, n) cin >> sign[i];
	sign[n] = l;
	FOR (i, 0, n) cin >> speed[i];
	speed[n] = 0;
	/* 5     8 3       6
	 * |     | |       |
	 * 0 1 2 3 4 5 6 7 8 9 10
	*/
	vector<vi> dp(n+1, vi(k+1, 1e9));
	dp[0][0] = 0;
	int ans=1e9;
	FOR (i, 1, n+1) {
		FOR (j, 0, k+1) {
			for (int p=i-1; p>=0; p--) {
				if (j-i+p+1 >= 0) {
					dp[i][j] = min(dp[i][j], dp[p][j-i+p+1] + (sign[i]-sign[p])*speed[p]);
				}
				if (i==n) ans=min(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
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

