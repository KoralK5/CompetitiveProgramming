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
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define F0Rd(i, a) for (int i=(a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef DEBUG
#define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << endl;
#else
#define dbg(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= rng();
        return x ^ (x >> 16);
    }
};
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; 

pair<ll, int> result(vector<int> a) {
	int n=a.size();
	if (n == 0) return mp(0, 0);
	if (n == 1) return mp((ll)a[0], abs(a[0])==2);
	int cnt=0; for (int &i : a) cnt += (i<0);
	if (cnt%2 == 0) {
		int two=0;
		ll ans=1;
		for (int &i : a) {
			ans *= i;
			ans %= MOD;
			two += abs(a[i])==2;
		}
		return mp(ans, two);
	}
	else if (cnt == 1) {
		int two1=0;
		ll ans1=1;
		for (int i=0; i<n; i++) {
			if (a[i]<0) break;
			ans1 *= a[i];
			ans1 %= MOD;
			two1 += abs(a[i])==2;
		}
		int two2=0;
		ll ans2=1;
		for (int i=n-1; i>=0; i--) {
			if (a[i]<0) break;
			ans2 *= a[i];
			ans2 %= MOD;
			two2 += abs(a[i])==2;
		}
		return two1>two2?mp(ans1, two1):mp(ans2, two2);
	}
	else {
		ll ans=1;
		for (int &i : a) {
			ans *= i;
			ans %= MOD;
		}
		int idx1=1;
		for (int i=0; i<n; i++) {
			if (a[i]<0) {
				idx1 = i;
				break;
			}
		}
		int idx2=1;
		for (int i=n-1; i>=0; i--) {
			if (a[i]<0) {
				idx2 = i;
				break;
			}
		}
		int two1=0;
		ll ans1=1;
		for (int i=0; i<idx2; i++) {
			ans1 *= a[i];
			ans1 %= MOD;
			two1 += abs(a[i])==2;
		}
		int two2=0;
		ll ans2=1;
		for (int i=n-1; i>idx1; i--) {
			ans2 *= a[i];
			ans2 %= MOD;
			two2 += abs(a[i])==2;
		}
		return two1>two2?mp(ans1, two1):mp(ans2, two2);
	}
}

void solve() {
	int n; cin >> n;
	vi nums(n); FOR (i, 0, n) cin >> nums[i];
	vector<vector<int>> a;
	a.push_back({});
	for (int &i : nums) {
		if (i == 0) {
			a.push_back({});
			continue;
		}
		a[a.size()-1].push_back(i);
	}
	bool one=false;
	trav (i, nums) one |= i==1;
	ll ans=one?1:-1e18;
	int mxtwo=0;
	for (vector<int> &b : a) {
		pair<ll, int> res = result(b);
		if (res.sec >= mxtwo) {
			mxtwo = res.sec;
			ans = res.fir;
		}
	}
	cout << ans << nl;
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

