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
	int n; cin >> n;
	// |p[i+1] - p[i]| is prime
	// distinct p[i+1] - p[i] is min
	// somehow we have to pair up prime differences
	// n = 10^6 => it's probably meant to be precomputed
	if (n%5!=0 && n%2!=0) {
		cout << -1 << nl;
		return;
	}
	// find a pattern that leads to the 2nd nearest multiple of 5 such that there are no holes
	// for n=10m, the same pattern holds
	// so reach n=10m
	
	if (n%2 == 0) {
		vi nums;
		if ((n-2)%5 == 0) {
			nums = {0, 2, 5, 3, 1, 4, 6, 9, 7, 10, 8, 11};
		}
		else if ((n-4)%5 == 0) {
			nums = {0, 2, 5, 3, 1, 4, 6, 8, 11, 9, 12, 10, 13};
		}
		else {
			cout << -1 << nl;
			return;
		}
		trav (j, nums) {
			cout << n-j << ' ';
		}
		n -= sz(nums);
	}
	if (n%5 == 0) {
		vi nums = {0, 3, 1, 4, 2};
		for (int i=n; i>0; i-=5) {
			trav (j, nums) {
				cout << i-j;
				if (i>5 || j!=2) cout << ' ';
			}
		}
	}
	cout << nl;
	
	/*
	int num=n;
	for (int i=0; i<n; i++) {
		cout << num;
		if (i<n-1) cout << ' ';

		if (i!=0 && i%10==0) {
			num-=3;
		}
		else if (i%2==0) num-=3;
		else num+=2;
	}
	*/
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

