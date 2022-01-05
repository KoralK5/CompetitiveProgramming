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

int n, k; 
int minScore(vector<string> &s) {
	int res=1e9, score;
	FOR (i, 0, n) {
		score = 0;
		FOR (j, 0, k) {
			score += (s[i][j]=='T');
		}
		res = min(res, score);
	}
	return res;
}
 
void solve() {
	cin >> n >> k;
	vector<string> quiz(n);
	FOR (i, 0, n) cin >> quiz[i];

	// change index i and compare each change to j
	int ans=minScore(quiz);
	vector<string> curQuiz;
	FOR (i, 0, k) {
		FOR (j, 0, n) {
			if (quiz[j][i] == 'T') {
				quiz[j][i] = 'F';
			}
			else {
				quiz[j][i] = 'T';
			}
		}
		FOR (j, i+1, k) {
			curQuiz = quiz;
			FOR (v, 0, n) {
				if (curQuiz[v][j] == 'T') {
					curQuiz[v][j] = 'F';
				}
				else {
					curQuiz[v][j] = 'T';
				}
			}
			ans = min(ans, minScore(curQuiz));
		}
	}
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

