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

int n, m, k;
vector<vi> a;
vi dx = {0, 0, -1, 1};
vi dy = {-1, 1, 0, 0};

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int bfs(int x, int y) {
	if (a[x][y] != 0) return a[x][y];

	unordered_map<pi, bool, hash_pair> visited;
	queue<vi> que;

	int best=1e9, bestDist=k;
	bool seen=0;
	visited[{x, y}] = true;
	que.push({x, y, 0});
	while (!que.empty()) {
		vi node = que.front();
		que.pop();

		// this could be problematic
		if (node[2] == bestDist) break;
		FOR (d, 0, 4) {
			int nx = node[0] + dx[d];
			int ny = node[1] + dy[d];
			if (nx>=0 && nx<n && ny>=0 && ny<m && !visited[{nx, ny}]) {
				if (a[nx][ny] != 0) {
					seen = 1;
					if (node[2]+1 < bestDist)
						best = a[nx][ny];
					else
						best = min(best, a[nx][ny]);

					bestDist = node[2]+1;
				}
				visited[{nx, ny}] = true;
				que.push({nx, ny, node[2]+1});
			}
		}
	}
	return best*seen;
}

void solve() {
	cin >> n >> m >> k;
	a.resize(n, vi(m));
	queue<vi> que;
	bool zo = true;
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cin >> a[i][j];
			if (a[i][j]) que.push({i, j, 0});
			if (a[i][j]!=0 && a[i][j]!=1) zo=false;
		}
	}

	vector<vi> b(n, vi(m, 0));
	// at each point, bfs for the closest color
	if (!zo) {
		FOR (i, 0, n) {
			FOR (j, 0, m) {
				b[i][j] = bfs(i, j);
			}
		}
	}

	else {
		unordered_map<pi, bool, hash_pair> visited;
		while (!que.empty()) {
			if (!rand()%5) break;
			vi node = que.front();
			que.pop();

			b[node[0]][node[1]] = 1;
			visited[{node[0], node[1]}] = true;

			FOR (d, 0, 4) {
				int nx = node[0] + dx[d];
				int ny = node[1] + dy[d];

				if (nx>=0 && nx<n && ny>=0 && ny<m && !visited[{nx, ny}] && node[2]+1 <= k) {
					visited[{nx, ny}] = true;
					que.push({nx, ny, node[2]+1});
				}
			}
		}
	}

	trav (i, b) {
		trav (j, i) {
			cout << j << ' ';
		}
		cout << nl;
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

