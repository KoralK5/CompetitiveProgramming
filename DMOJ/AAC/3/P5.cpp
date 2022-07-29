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

vi dx = {-1, 1, 0, 0};
vi dy = {0, 0, -1, 1};

void solve() {
	int n, m; cin >> n >> m;
	vector<string> a(n); FOR (i, 0, n) cin >> a[i];
	map<pair<pair<int, int>, pair<int, int>>, int> water;
	vector<bool> rem(m, false);
	vi res(m, -1);
	FOR (i, 0, m) {
		if (rem[i]) continue;
		if (a[n-1][i] == '.') {
			res[i] = -1;
			continue;
		}
		vector<vi> vis(n, vi(m, 0));
		queue<vi> que;

		// find the whole land section
		set<int> con;
		vector<vi> seen(n, vi(m, 0));
		queue<pi> land;
		seen[n-1][i] = true;
		land.push({n-1, i});
		while (!land.empty()) {
			pi node = land.front();
			land.pop();
			int x = node.fir;
			int y = node.sec;
			if (x == n-1) con.ins(y);
			FOR (i, 0, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
				if (seen[nx][ny]) continue;
				if (a[nx][ny] == '.') continue;
				seen[nx][ny] = true;
				land.push(mp(nx, ny));
			}
		}

		vis[n-1][i] = 1e9;
		que.push({n-1, i, int(1e9)});

		while (!que.empty()) {
			vi node = que.front();
			que.pop();

			int x = node[0];
			int y = node[1];
			int size = node[2];

			FOR (j, 0, 4) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
				if (vis[nx][ny] >= size) continue;

				if (a[nx][ny] == '#') {
					vis[nx][ny] = size;
					que.push({nx, ny, size});
				}
				else {
					int cx=nx, cy=ny, dist=0;
					int dVal = water[mp(mp(x, y), mp(nx, ny))];
					if (dVal == 0) {
						while (a[cx][cy] != '#') {
							cx += dx[j];
							cy += dy[j];
							if (cx<0 || cx>=n || cy<0 || cy>=m) {
								dist = -1;
								break;
							}
							dist++;
						}
						water[mp(mp(x, y), mp(nx, ny))] = dist;
					}
					else {
						dist = dVal;
						cx += dx[j]*dVal;
						cy += dy[j]*dVal;
					}
					if (dist != -1) {
						int curSize = min(size, dist);
						if (vis[cx][cy] >= curSize) continue;
						vis[cx][cy] = curSize;
						que.push({cx, cy, curSize});
					}
				}
			}
		}

		int ans = *max_element(all(vis[0]));

		if (ans == 0) ans = -1;
		if (ans >= 1e9) ans = 0;

		trav (i, con) {
			res[i] = ans;
			rem[i] = true;
		}
	}
	FOR (i, 0, m) cout << res[i] << " \n"[i==m-1];
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
