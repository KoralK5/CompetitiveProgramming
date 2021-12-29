#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
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
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lbound lower_bound
#define ubound upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 
 
void solve() {
	float n, m; cin>>n>>m;
	vector<vector<char>> rec;
	string curr;
	for (int i=0; i<n; i++) {
		cin>>curr;
		vector<char> cVec(curr.begin(), curr.end());
		rec.pb(cVec);
	}
	int opHor, opVer;
	char opHorC, opVerC;
	for (int i=0; i<n; i++) {
		opVer = n-i-1;
		for (int j=0; j<m; j++) {
			opHor = m-j-1;
			opHorC = rec[i][opHor];
			opVerC = rec[opVer][j];
			if (n==m && i+.5==n/2 && j+.5==m/2 && rec[i][j]=='.') {
				rec[i][j] = 'o';
			}
			else if (rec[i][j] == '.') {
				if (opHorC!='.' && opVerC!='.') {
					if (opHorC != opVerC) {
						cout<<-1;
						return;
					}
					else {
						rec[i][j] = opHorC;
					}
				} else {
					if (opHorC == '.' && opVerC == '.') {
						rec[i][j] = 'o';
						rec[i][opHor] = 'o';
						rec[opVer][j] = 'o';
					}
					else if (opHorC != '.') {
						rec[i][j] = opHorC;
						rec[opVer][j] = opHorC;
					} else {
						rec[i][j] = opVerC;
						rec[i][opHor] = opVerC;
					}
				}
			}
			else {
				if ((rec[i][j] != opHorC && opHorC!='.') || (rec[i][j] != opVerC && opVerC!='.')) {
					cout<<-1;
					return;
				}
				else {
					rec[i][opHor] = rec[i][j];
					rec[opVer][j] = rec[i][j];
				}
			}
		}
	}

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout<<rec[i][j];
		}
		cout<<nl;
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

