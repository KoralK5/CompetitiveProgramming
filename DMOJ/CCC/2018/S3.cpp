/*
ID: Koral Kulacoglu
TASK: https://dmoj.ca/problem/ccc18s3
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

int n, m;
vs a;

bool available(int x, int y) {
	if (a[x][y] == 'W') return false;
	for (int i=x; i<n; i++) {
		if (a[i][y] == 'W') break;
		if (a[i][y] == 'C') return false;
	}
	for (int i=x; i>=0; i--) {
		if (a[i][y] == 'W') break;
		if (a[i][y] == 'C') return false;
	}
	for (int i=y; i<m; i++) {
		if (a[x][i] == 'W') break;
		if (a[x][i] == 'C') return false;
	}
	for (int i=y; i>=0; i--) {
		if (a[x][i] == 'W') break;
		if (a[x][i] == 'C') return false;
	}
	return true;
}
 
void solve() {
	cin >> n >> m;
	vi start(3);
	map<vi, int> visited;
	string curr;
	FOR (i, 0, n) {
		cin >> curr;
		a.pb(curr);
		FOR (j, 0, m) {
			if (curr[j] == 'S') {
				start[0] = i;
				start[1] = j;
				start[2] = 0;
			}
			if (curr[j]!='W' && curr[j]!='C') {
				visited[{i, j}] = -1;
			}
		}
	}

	// use bfs
	queue<vi> q; //x, r, dist
	q.push(start);
	visited[{start[0], start[1]}] = start[2];

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	while (!q.empty()) {
		vi node = q.front();
		q.pop();
		FOR (i, 0, 4) {
			int x = node[0]+dx[i];
			int y = node[1]+dy[i];
			int d = node[2]+1;
			if (x<0 || x>=n || y<0 || y>=m) continue;

			if (visited[{x, y}]==-1) {
				if (a[x][y] == '.') {
					if (available(x, y)) {
						visited[{x, y}] = d;
						q.push({x, y, d});
					}
				}
				// if it's a conveyer belt, go until the end
				// mark everything in the path as visited
				else {
					while (true) {
						char loc=a[x][y];
						if (loc!='D' && loc!='U' && loc!='R' && loc!='L') break;
						int px=x, py=y;
						x += (loc=='D')-(loc=='U');
						y += (loc=='R')-(loc=='L');
						if (visited[{x, y}]!=-1) break;
						visited[{px, py}] = 0;
					}
					if (a[x][y]=='.' && available(x, y)) {
						visited[{x, y}] = d;
						q.push({x, y, d});
					}
				}
			}
		}
	}
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (visited[{i,j}]!=0) {
				cout << visited[{i,j}] << nl;
			}
		}
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

