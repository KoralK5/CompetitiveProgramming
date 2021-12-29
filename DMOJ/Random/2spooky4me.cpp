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
	int n, l, s; cin>>n>>l>>s;
	vector<vector<int>> houses(n, vector<int>(4));
	set<int> unique;

	// houses[j][0 & 1] are the ranges
	// houses[j][2] are the amounts of spook 
	// houses[j][3] are the amounts of houses
	FOR (i, 0, n) {
		cin>>houses[i][0]>>houses[i][1]>>houses[i][2];
		houses[i][1]++;
		houses[i][3] = houses[i][1] - houses[i][0];
		unique.ins(houses[i][0]);
		unique.ins(houses[i][1]);
	}
	map<int, int> comps;
	int idx=0;
	for (int i : unique) {
		comps[i] = idx;
		idx++;
	}
	FOR (i, 0, n) {
		houses[i][0] = comps[houses[i][0]];
		houses[i][1] = comps[houses[i][1]];
	}
	vector<vi> compHouses(unique.size(), vi(2));
	cout<<nl;
	FOR (i, 0, n) {
		FOR (j, houses[i][0], houses[i][1]) {
			compHouses[j][0] += houses[i][2];
			compHouses[j][1] = houses[i][3]/(houses[i][1]-houses[i][0]-1);
		}
	}
	FOR (i, 0, compHouses.size()) {
		cout<<compHouses[i][0]<<" "<<compHouses[i][1]<<nl;
		if (compHouses[i][0] >= s) {
			l -= compHouses[i][1];
		}
	}
	cout<<l;
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

