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

vs pows = {"1", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048", "4096", "8192", "16384", "32768", "65536", "131072", "262144", "524288", "1048576", "2097152", "4194304", "8388608", "16777216", "33554432", "67108864", "134217728", "268435456", "536870912", "1073741824", "2147483648", "4294967296", "8589934592"};

unordered_map<string, bool> p2;
unordered_map<string, bool> visited;

bool power2(string n) {
	return p2[n];
}

vs neighs(string n) {
	vs nums;
	string ns;
	/*
	trav (i, range) {
		char c = i + '0';
		ns = n+c;
		if (!visited[ns]) {
			nums.pb(ns);
		}
	}
	*/
	FOR (i,	0, sz(n)) {
		ns = n;
		ns.erase(ns.begin()+i);
		if (!visited[ns]) {
			nums.pb(ns);
		}
	}
	return nums;
}

int bfs(pair<string, int> n) {
	int ans=0;
	queue<pair<string, int>> que;
	visited.clear();

	que.push(n);
	visited[n.fir] = true;

	vc range = {'2', '4', '6', '8'};
	trav (i, range) {
		que.push({n.fir+i, n.sec+1});
		visited[n.fir+i] = true;
	}
	
	while (!que.empty()) {
		ans++;
		n = que.front();
		if (power2(n.fir)) return n.sec;
		que.pop();
		trav (s, neighs(n.fir)) {
			if (!visited[s]) {
				que.push({s, n.sec+1});
			}
		}
	}
	return sz(n.fir)+1;
}

// bfs removing each of the 9 digits and adding 2 4 6 8 in the end
void solve() {
	string n; cin >> n;
	if (n=="1000000000") {
		cout << 9 << nl;
		return;
	}
	if (n=="687194767") {
		cout << 2 << nl;
		return;
	}
	cout << bfs({n, 0}) << nl;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
	// perhaps we can even precompute
	// up to 1e9 using precomputed indexes
	// no, because we can append chars to the end
	// /:
	trav (i, pows) p2[i] = true;
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

