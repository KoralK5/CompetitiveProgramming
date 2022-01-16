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
 
void solve() {
	// observation: go backwards
	// saves (n*m + multiple visits) time
	int r, c; cin >> r >> c;
	vs a(r); FOR (i, 0, r) cin >> a[i];
	int m; cin >> m;
	vc moves(m); for (int i=m-1; i>=0; i--) cin >> moves[i];

	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (a[i][j]=='.') {
				vc dirs = {'u', 'd', 'l', 'r'};
				bool works;
				trav (dir, dirs) {
					works = true;
					int x=i, y=j;
					trav (mo, moves) {
						if (mo=='F') {
							if (dir=='d') x--;
							if (dir=='u') x++;
							if (dir=='r') y--;
							if (dir=='l') y++;
						}
						else if (mo=='R') {
							if (dir=='u') dir='l';
							else if (dir=='l') dir='d';
							else if (dir=='d') dir='r';
							else if (dir=='r') dir='u';
						}
						else if (mo=='L') {
							if (dir=='u') dir='r';
							else if (dir=='r') dir='d';
							else if (dir=='d') dir='l';
							else if (dir=='l') dir='u';
						}
						if (x<0 || y<0 || x>=r || y>=c || a[x][y]!='.') {
							works = false;
							break;
						}
					}
					if (works) break;
				}
				if (works) cout << '*';
				else cout << a[i][j];
			}
			else {
				cout << a[i][j];
			}
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

