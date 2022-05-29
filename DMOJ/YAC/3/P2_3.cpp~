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

#define MAX 1000
#define log 10

int level[MAX];
int lca[MAX][log];
int dist[MAX][log];
vector<pair<int, int> > graph[MAX];
 
void addEdge(int u, int v, int cost) {
    graph[u].push_back({ v, cost });
    graph[v].push_back({ u, cost });
}
 
void dfs(int node, int parent, int h, int cost) {
    lca[node][0] = parent;
    level[node] = h;
    if (parent != -1) {
        dist[node][0] = cost;
    }
    for (int i = 1; i < log; i++) {
        if (lca[node][i - 1] != -1) {
            lca[node][i]
                = lca[lca[node]
                         [i - 1]]
                     [i - 1];
 
            dist[node][i]
                = dist[node][i - 1]
                  + dist[lca[node][i - 1]]
                        [i - 1];
        }
    }
 
    for (auto i : graph[node]) {
        if (i.first == parent)
            continue;
        dfs(i.first, node, h + 1, i.second);
    }
}
 
int findDistance(int u, int v) {
    int ans = 0;
    if (level[u] > level[v])
        swap(u, v);
 
    for (int i = log - 1; i >= 0; i--) {
        if (lca[v][i] != -1
            && level[lca[v][i]]
                   >= level[u]) {
            ans += dist[v][i];
            v = lca[v][i];
        }
    }
 
    if (v == u) {
		return ans;
    }
 
    else {
        for (int i = log - 1; i >= 0; i--) {
            if (lca[v][i] != lca[u][i]) {
                ans += dist[u][i] + dist[v][i];
                v = lca[v][i];
                u = lca[u][i];
            }
        }
 
        ans += dist[u][0] + dist[v][0];
		return ans;
    }
}

void solve2(ll n) {
	n--;
	for (ll i=1; i<n+2; i++) cout << -6*i*i + i*(n*6 + 12) - (n*3 + 5) << ' ';
	cout << nl;
}
 
void solve() {
	int n; cin >> n;
	bool lin=true;
	unordered_map<int, vi> graph;
	FOR (i, 0, n-1) {
		int u, v; cin >> u >> v;
		addEdge(u, v, 1);
		if (u!=i+1 || v!=i+2) lin = false;
	}
	if (lin) {
		solve2(n);
		return;
	}
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < log; j++) {
            lca[i][j] = -1;
            dist[i][j] = 0;
        }
    }

	dfs(1, -1, 0, 0);

	vi res(n, 0);
	FOR (a, 1, n+1) {
		FOR (b, 1, n+1) {
			FOR (c, 1, n+1) {
				int dist=1e9;
				int idx=1e9;
				FOR (pt, 1, n+1) {
					int da = findDistance(a, pt);
					int db = findDistance(b, pt);
					int dc = findDistance(c, pt);
					int dt = da + db + dc;
					if ((dt < dist) || (dt == dist && pt < idx)) {
						idx = pt;
						dist = dt;
					}
				}
				res[idx-1]++;
			}
		}
	}
	trav (i, res) cout << i << ' ';
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

