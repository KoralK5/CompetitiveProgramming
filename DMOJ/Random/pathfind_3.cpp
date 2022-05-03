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

struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);

		if (hash1 != hash2) {
			return hash1 ^ hash2;             
		}
		 
		return hash1;
	}
};

void print(unordered_map<pi, bool, hash_pair> a, int n, int m) {
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout << (a[{i, j}]?'#':'.') << ' ';
		}
		cout << nl;
	}
}

int n, m, k;
unordered_map<pi, bool, hash_pair> grid;

bool forward(int x, int y, char dir) {
	if (dir=='r') return grid[{x, y+1}];
	if (dir=='l') return grid[{x, y-1}];
	if (dir=='d') return grid[{x+1, y}];
	if (dir=='u') return grid[{x-1, y}];
	return false;
}

bool left(int x, int y, char dir) {
	if (dir=='r') return grid[{x-1, y}];
	if (dir=='l') return grid[{x+1, y}];
	if (dir=='d') return grid[{x, y+1}];
	if (dir=='u') return grid[{x, y-1}];
	return false;
}

pi go(int x, int y, char dir) {
	if (dir == 'r') return {x, y+1};
	if (dir == 'l') return {x, y-1};
	if (dir == 'd') return {x+1, y};
	if (dir == 'u') return {x-1, y};
	return {x, y};
}

char turn(char dir) {
	if (dir == 'r') return 'u';
	if (dir == 'd') return 'r';
	if (dir == 'l') return 'd';
	if (dir == 'u') return 'l';
	return dir;
}

char turnR(char dir) {
	if (dir == 'r') return 'd';
	if (dir == 'd') return 'l';
	if (dir == 'l') return 'u';
	if (dir == 'u') return 'r';
	return dir;
}

void solve() {
	cin >> n >> m >> k;
	n+=2; m+=2;
	FOR (i, 0, k) {
		int r, c; cin >> r >> c;
		grid[{r, c}] = true;
	}
	FOR (i, 0, n) grid[{i, 0}] = true;
	FOR (i, 0, n) grid[{i, n-1}] = true;
	FOR (j, 0, n) grid[{0, j}] = true;
	FOR (j, 0, n) grid[{m-1, j}] = true;
	// print(grid, n, m);

	/*
	if (turnedleft previously and forward no wall)
		 go forward;
	else if (no wall at left)
		 turn 90 deg left;
	else if (no wall forward)
		 go forward;
	else
		 turn 90 deg right;
	*/
	int x=1, y=1;
	char dir='r';
	bool prev=false;
	FOR (i, 0, 1e6) {
		// cout << x << ' ' << y << nl;
		if (x==n-2 && y==m-2) {
			cout << "YES" << nl;
			return;
		}
		if (prev && !forward(x, y, dir)) {
			pi vals = go(x, y, dir);
			x = vals.fir;
			y = vals.sec;
			prev = false;
		}
		else if (!left(x, y, dir)) {
			dir = turn(dir);
			prev = true;
		}
		else if (!forward(x, y, dir)) {
			pi vals = go(x, y, dir);
			x = vals.fir;
			y = vals.sec;
			prev = false;
		}
		else {
			dir = turnR(dir);
			prev = true;
		}
	}
	cout << "NO" << nl;
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

