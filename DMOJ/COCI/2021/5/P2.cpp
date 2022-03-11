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

int n, m, se=0;
vs a;
vector<vector<bool>> seen;
bool diamond(int i, int j) {
	// break until diamond or impossible
	int dist=1;
	bool lt=false;
	while (i+dist<n && j+dist<m && i-dist>=0 && j-dist>=0) {
		int count=0;
		bool tp=(a[i-1][j-(dist-1)])=='#';
		if (lt) return false;
		FOR (d, 1, dist+1) {
			int add=0;
			if (seen[i-d][j-(dist-d)] || seen[i+d][j+(dist-d)] || seen[i-(dist-d)][j+d] || seen[i+(dist-d)][j-d]) {
				lt = true;
			}
			add += (a[i-d][j-(dist-d)] == '#');
			add += (a[i+d][j+(dist-d)] == '#');
			add += (a[i-(dist-d)][j+d] == '#');
			add += (a[i+(dist-d)][j-d] == '#');

			if ((tp && add!=4) || (!tp && add!=0)) return false;
			count += add;
		}
		if (count == dist*4) {
			se = dist;
			return true;
		}
		dist++;
	}
	return false;
}
 
void solve() {
	cin >> n >> m;
	a.resize(n); FOR (i, 0, n) cin >> a[i];
	seen.resize(n, vector<bool>(m, false));
	int ans=0;
	FOR (i, 1, n-1) {
		FOR (j, 1, m-1) {
			if (a[i][j] == '.' && !seen[i][j]) {
				if (diamond(i, j)) {
					ans++;
					// seen[i-se][j] = true;
					seen[i+se][j] = true;

					// fill in seen
					/*
					int d=1;
					bool dir=true;
					FOR (k, i-se+1, i+se) {
						FOR (l, j-d, j+d+1) {
							seen[k][l] = true;
						}
						if (d == se) dir=false;
						if (dir) d++;
						else d--;
					}
					*/
					int d=se;
					FOR (k, i, i+se) {
						FOR (l, j, j+d+1) {
							seen[k][l] = true;
						}
						d--;
					}
				}
			}
		}
	}
	/*
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout << seen[i][j];
		}
		cout << nl;
	}
	*/
	cout << ans << nl;
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

