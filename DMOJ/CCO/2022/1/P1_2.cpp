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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int n, k, q; 
vi a;

/*
bool check(int x, int y) {
	vector<vector<bool>> rel(k+1, vector<bool>(k+1));
	FOR (i, x, y) {
		int cur=a[i], nxt=a[i+1];
		if (cur == nxt) return false;

		if (rel[cur][nxt] && (i%2)) return false;
		if (rel[nxt][cur] && !(i%2)) return false;

		// nxt > cur
		if (i%2) rel[nxt][cur] = true;

		// nxt < cur
		else rel[cur][nxt] = true;
	}
	return true;
}
*/

bool valid(int x, int y, vi mp) {
	bool gt=(a[x]>a[y]);
	FOR (i, x, y) {
		int cur=mp[a[i]], nxt=mp[a[i+1]];

		if (cur == nxt) return false;
		if (gt ^ (cur>nxt)) return false;
		gt = !gt;
	}
	return true;
}

bool check3(int x, int y) {
	vi mp(3);
	FOR (a, 0, 3) {
		FOR (b, 0, 3) {
			if (a==b) continue;
			FOR (c, 0, 3) {
				if (c==b || c==a) continue;
				mp[0] = a;
				mp[1] = b;
				mp[2] = c;
				if (valid(x, y, mp)) return true;
			}
		}
	}
	return false;
}

bool check4(int x, int y) {
	vi mp(4);
	FOR (a, 0, 4) {
		FOR (b, 0, 4) {
			if (a==b) continue;
			FOR (c, 0, 4) {
				if (c==b || c==a) continue;
				FOR (d, 0, 4) {
					if (d==c || d==b || d==a) continue;
					mp[0] = a;
					mp[1] = b;
					mp[2] = c;
					mp[3] = d;
					if (valid(x, y, mp)) return true;
				}
			}
		}
	}
	return false;
}

bool check5(int x, int y) {
	vi mp(5);
	FOR (a, 0, 5) {
		FOR (b, 0, 5) {
			if (a==b) continue;
			FOR (c, 0, 5) {
				if (c==b || c==a) continue;
				FOR (d, 0, 5) {
					if (d==c || d==b || d==a) continue;
					FOR (e, 0, 5) {
						if (e==d || e==c || e==b || e==a) continue;
						mp[0] = a;
						mp[1] = b;
						mp[2] = c;
						mp[3] = d;
						mp[4] = e;
						if (valid(x, y, mp)) return true;
					}
				}
			}
		}
	}
	return false;
}

bool check2(int x, int y) {
	FOR (i, x, y) if (a[i] == a[i+1]) return false;
	return true;
}
 
void solve() {
	cin >> n >> k >> q;
	a.resize(n); FOR (i, 0, n) cin >> a[i];
	FOR (i, 0, q) {
		int x, y; cin >> x >> y; x--; y--;
		if (k == 2) cout << (check2(x, y)?"YES":"NO") << nl;
		if (k == 3) cout << (check3(x, y)?"YES":"NO") << nl;
		if (k == 4) cout << (check4(x, y)?"YES":"NO") << nl;
		if (k == 5) cout << (check5(x, y)?"YES":"NO") << nl;
	}
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

