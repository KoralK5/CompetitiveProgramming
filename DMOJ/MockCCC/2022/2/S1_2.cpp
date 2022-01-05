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
	int n, k; cin >> n >> k;
	vi per(n), sco(k);
	vector<string> res(n);
	FOR (i, 0, n) {
		cin >> res[i];
		FOR (j, 0, k) {
			if (res[i][j] == 'T') {
				per[i]++;
				sco[j]++;
			}
		}
	}
	FOR (t, 0, 5000) {
		int mIdx=0, mVal=1e4+1;
		FOR (i, 0, n) {
			if (per[i] < mVal) {
				mVal = per[i];
				mIdx = i;
			}
		}
		int mIdx2=0, mVal2=1e4+1;
		FOR (i, 0, k) {
			if (res[mIdx][i] == 'F' && sco[i] < mVal2) {
				mVal2 = sco[i];
				mIdx2 = i;
			}
		}
		// cout << mIdx << " " << mIdx2;
		if (res[mIdx][mIdx2] == 'F') {
			FOR (i, 0, n) {
				if (res[i][mIdx2] == 'T') {
					res[i][mIdx2] = 'F';
					sco[mIdx2]--;
					per[i]--;
				}
				else {
					res[i][mIdx2] = 'T';
					sco[mIdx2]++;
					per[i]++;
				}
			}
		}
	}
	int ans=1e4+1;
	FOR (i, 0, n) {
		ans = min(ans, per[i]);
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

