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

int n, k;
vi skills;
vi nums(2e5, 0);
unordered_map<int, vector<pi>> bp;

// find the range of numbers that will work for each node using dfs and increment a range at the same time
void dfs(int node, int mn, int mx) {
	if (mn > mx) return;

	trav (i, skills) {
		if (mn <= i && i <= mx)
			nums[node-1]++;
	}

	int size = sz(bp[node]);

	if (size==0 || node==n) return;

	if (size == 1) {
		dfs(bp[node][0].fir, mn, mx);
		return;
	}

	// for each number, check left and right side to find min and max, then dfs with that
	FOR (i, 0, size) {
		if (node >= bp[node][i].fir) continue;
		if (i==0) {
			dfs(bp[node][i].fir, mn, min(mx, (bp[node][i].sec+bp[node][i+1].sec)/2));
		}
		else if (i == size-1) {
			dfs(bp[node][i].fir, max(mn, (bp[node][i].sec+bp[node][i-1].sec+2)/2), mx);
		}
		else {
			dfs(bp[node][i].fir, max(mn, (bp[node][i].sec+bp[node][i-1].sec+2)/2), min(mx, (bp[node][i].sec+bp[node][i+1].sec)/2));
		}
	}
}

bool compare(pi a, pi b) {
	return a.sec < b.sec;
}

void solve() {
	// directed graph
	cin >> n >> k;
	// a <b, d>
	int a, b, d;
	FOR (i, 0, n-1) {
		cin >> a >> b >> d;
		bp[a].pb({b, d});
	}

	// pre-sort the map 
	trav (i, bp) sort(all(i.sec), compare);

	int s;
	FOR (i, 0, k) {
		cin >> s;
		skills.pb(s);
	}

	// node min  max
	dfs(1, -1e9, 1e9);

	FOR (i, 0, n) {
		cout << nums[i];
		if (i != n) cout << ' ';
	}
	cout << nl;
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

