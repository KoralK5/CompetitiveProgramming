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


// A queue node used in BFS
typedef pair<int, int> Node;
 
// Below arrays detail all four possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
 
// Function to check if it is possible to go to position `pt`
// from the current position. The function returns false if `pt` is
// not in a valid position, or it is already visited
bool isValid(Node pt, map<Node, int> visited, int N)
{
    return (pt.first >= 0) && (pt.first < N) &&
        (pt.second >= 0) && (pt.second < N) && !visited.count(pt);
}
 
// Find the shortest path length in a matrix from source cell (x, y) to
// destination cell (N-1, N-1)
int findPath(vector<vector<int>> const &mat, int x, int y)
{
    // `N × N` matrix
    int N = mat.size();
    int M = mat[0].size();
 
    // create a queue and enqueue the first node
    queue<Node> q;
    Node src = {x, y};
    q.push(src);
 
    // map to check if the matrix cell is visited before or not. It also
    // stores the shortest distance info, i.e., the value corresponding
    // to a node in the map represents its shortest distance from the source
    map<Node, int> visited;
    visited[src] = 0;
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and process it
        Node node = q.front();
        q.pop();
 
        int i = node.first;
        int j = node.second;
        int dist = visited[node];
 
        // if the destination is found, return true
        if (i == N - 1 && j == M - 1) {
            return dist;
        }
 
        // value of the current cell
        int n = mat[i][j];
 
        // check all four possible movements from the current cell
        // and recur for each valid movement
        for (int k = 0; k < 4; k++)
        {
            // get the next position using the value of the current cell
            Node next = {(i + row[k] * n), (j + col[k] * n)};
 
            // check if it is possible to go to position (x, y)
            // from the current position
            if (isValid(next, visited, N))
            {
                q.push(next);
                visited[next] = dist + 1;
            }
        }
    }
 
    // return a negative number if the path is not possible
    return -1;
}
 
void solve() {
	int n, m; cin >> n >> m;
	vector<vi> matrix(n, vi(m));
	FOR (i, 0, n) {
		string s; cin >> s;
		FOR (j, 0, m) {
			if (s[j] == 'C')
				matrix[i][j] = 10000;
			else
				matrix[i][j] = 1;
		}
	}

    int path = findPath(matrix, 0, 0);
	cout << path/100 << nl;
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

