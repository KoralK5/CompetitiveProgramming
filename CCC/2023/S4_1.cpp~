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

// function to find the parent of the node in a graph
int findParent(int x, int *parent)
{
    if (parent[x] == x)
        return x;
    return findParent(parent[x], parent);
}
// function to find the union of the two nodes
void UnionTwoNodes(int *parent, int *rank, int *minVal, int x, int y)
{
    // Finding parent of Node x
    x = findParent(x, parent);
    // Finding parent of Node y
    y = findParent(y, parent);
    // If rank of both the nodes are same, simply increase rank of first node
    if (rank[x] == rank[y])
        rank[x]++;

    if (rank[x] > rank[y])
    {
        parent[y] = x;
        // updating the minVal array to store the minValue greater than 0.
        if (minVal[x] < 0 && minVal[y] < 0)
        {
            minVal[x] = max(minVal[x], minVal[y]);
        }
        else if (minVal[x] < 0 && minVal[y] >= 0)
        {
            minVal[x] = minVal[y];
        }
        else if (minVal[x] >= 0 && minVal[y] >= 0)
        {
            minVal[x] = min(minVal[x], minVal[y]);
        }
    }
    else
    {
        parent[x] = y;
        // updating the minVal array to store the minValue greater than 0.
        if (minVal[x] < 0 && minVal[y] < 0)
        {
            minVal[y] = max(minVal[x], minVal[y]);
        }
        else if (minVal[x] >= 0 && minVal[y] < 0)
        {
            minVal[y] = minVal[x];
        }
        else if (minVal[x] >= 0 && minVal[y] >= 0)
        {
            minVal[x] = min(minVal[x], minVal[y]);
        }
    }
}
// function to find the minimum cost to connect the graph
int findMinCost(vector<pair<int, int>> &graph, int *cost, int n, int m)
{
    // declaring parent array to store the parent for every node,
    // initially every node is its own parent
    int *parent = new int[n + 1];
    // rank array to store the rank of every node
    int *rank = new int[n + 1];
    // stores the minimum value of each set
    int *minVal = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        // initially every node is its own parent
        parent[i] = i;
        // initially rank of every node is 0.
        rank[i] = 0;
        minVal[i] = cost[i - 1];
    }
    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        // grouping the nodes that are connected, by making their parent Node same
        UnionTwoNodes(parent, rank, minVal, it->first, it->second);
    }

    // map to store parent of each connected component
    unordered_set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(parent[i]);
    }

    // variable to store the min value for the set with its index.
    pair<int, int> minStore = {0, INT_MAX};
    // flag variable that keep the check if minimum value is not less than 0.
    // if less than 0, then true, otherwise false.
    bool flag = false;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        // if minVal is less than 0,
        if (minVal[*it] < 0)
        {
            // mark flag as true
            flag = true;
        }
        if (minStore.second > minVal[*it])
        {
            minStore.first = *it;
            minStore.second = minVal[*it];
        }
    }
    // it will store the final answer, minimum cost to add the edges
    int ans = 0;
    if (flag == false)
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it != minStore.first)
            {
                ans += (minVal[*it] + minStore.second);
            }
        }
    }
    else if (flag && s.size() == 1)
    {
        ans = 0;
    }
    else
    {
        ans = -1;
    }
    return ans;
}

void solve() {
	int n, m; cin >> n >> m;

	vector<pair<int, int>> graph;
	int cost[m];
	FOR (i, 0, m) {
		ll u, v, l, c; cin >> u >> v >> l >> c;
		graph.pb(mp(u, v));
		cost[i] = c;
	}

	cout << findMinCost(graph, cost, n, m) << nl;
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

