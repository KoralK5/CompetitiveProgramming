
// ERROR ON FACEBOOK END

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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

// add every possible tree
// remove trees if they don't work using bfs
// at the check if end everything works

vi dx = {-1, 1, 0, 0};
vi dy = {0, 0, -1, 1};
 
void solve() {
	int r, c; cin >> r >> c;
	vector<string> s(r); FOR (i, 0, r) cin >> s[i];
	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (s[i][j] == '.') s[i][j] = 'v';
		}
	}

	queue<pi> que;
	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (s[i][j] != 'v') continue;

			int friends = 0;
			friends += i-1>=0 ? s[i-1][j]=='^' || s[i-1][j]=='v' : 0;
			friends += i+1<r ? s[i+1][j]=='^' || s[i+1][j]=='v' : 0;
			friends += j-1>=0 ? s[i][j-1]=='^' || s[i][j-1]=='v' : 0;
			friends += j+1<c ? s[i][j+1]=='^' || s[i][j+1]=='v' : 0;

			if (friends < 2) {
				que.push(mp(i, j));
			}
		}
	}

	while (!que.empty()) {
		pi node = que.front();
		que.pop();

		int x = node.fir;
		int y = node.sec;
		s[x][y] = '.';

		FOR (i, 0, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || nx>=r || ny<0 || ny>=c) continue;
			if (s[nx][ny] != 'v') continue;

			int friends = 0;
			friends += nx-1>=0 ? s[nx-1][ny]=='^' : 0;
			friends += nx+1<r ? s[nx+1][ny]=='^' : 0;
			friends += ny-1>=0 ? s[nx][ny-1]=='^' : 0;
			friends += ny+1<c ? s[nx][ny+1]=='^' : 0;

			if (friends < 2) {
				que.push(mp(nx, ny));
			}
		}
	}

	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (s[i][j] == 'v') s[i][j] = '^';
		}
	}

	FOR (x, 0, r) {
		FOR (y, 0, c) {
			if (s[x][y]!='^') continue;

			int friends = 0;
			friends += x-1>=0 ? s[x-1][y]=='^' : 0;
			friends += x+1<r ? s[x+1][y]=='^' : 0;
			friends += y-1>=0 ? s[x][y-1]=='^' : 0;
			friends += y+1<c ? s[x][y+1]=='^' : 0;

			if (friends < 2) {
				cout << "Impossible" << nl;
				return;
			}
		}
	}

	cout << "Possible" << nl;
	FOR (i, 0, r) {
		FOR (j, 0, c) {
			cout << s[i][j];
		}
		cout << nl;
	}
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

	freopen("second_second_friend_input.txt", "r", stdin);
	freopen("B2.txt", "w", stdout);    
 
    int T = 1;
	cin >> T;
	FOR (i, 1, T+1) {
		cout << "Case #" << i << ": ";
        solve();
    }
 
	return 0;
}

