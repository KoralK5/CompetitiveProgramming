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

int ask(int i, int j) {
	cout << "? " << i << " " << j << nl;
	cout << flush;
	int n; cin >> n; return n;
}

void pt(int a, int b, int c) {
	cout << a << ' ' << b << ' ' << c << nl;
}
 
void solve() {
	int n; cin >> n;

	if (n == 3) {
		int a = ask(1, 2);
		int b = ask(2, 3);
		
		cout << "! ";
		if (a==2 && b==6) pt(1,2,3);
		if (a==3 && b==6) pt(1,3,2);
		if (a==6 && b==3) pt(2,3,1);
		if (a==2 && b==3) pt(2,1,3);
		if (a==6 && b==2) pt(3,2,1);
		if (a==3 && b==2) pt(3,1,2);
		return;
	}

	double ab = ask(1, 2);
	double ac = ask(1, 3);
	double bc = ask(2, 3);

	double bDc = ab/ac;
	int b = sqrt(bDc*bc);
	int a = ab/b;
	int c = bc/b;

	vi arr(n-1);
	vector<bool> sa(n, false);

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sa[a-1] = true;
	sa[b-1] = true;
	sa[c-1] = true;

	FOR (i, 3, n-1) {
		arr[i] = ask(i, i+1)/arr[i-1];
		sa[arr[i]-1] = true;
	}

	cout << "! ";
	trav (i, arr) cout << i << ' ';

	FOR (i, 0, n) {
		if (!sa[i]) {
			cout << i+1 << nl;
			break;
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

