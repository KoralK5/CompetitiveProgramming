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
	int n; cin >> n;
	/*
	unordered_map<int, bool> nums;
	FOR (i, 1, n+1) nums[i] = true;
	vi primes;
	int arr[n+1] = {0};
   for (int i = 2; i <= n; i++) {
      for (int j = i * i; j <= n; j+=i) {
         arr[j - 1] = 1;
      }
   }
   for (int i = 1; i <= n; i++) {
      if (arr[i - 1] == 0)
		  primes.pb(i);
   }

	// greedy??
	FOR (i, 1, n+1) {
		trav (p, primes) {
			if (nums[p-i]) {
				nums[p-i] = false;
				cout << p-i;
				if (i!=n) cout << ' ';
			}
		}
	}
	*/
	if (n==1) {
		cout << "1\n";
	}
	else if (n==2) {
		cout << "2 1\n";
	}
	else if (n==3) {
		cout << "1 3 2\n";
	}
	else if (n==4) {
		cout << "2 1 4 3\n";
	}
	else if (n==5) {
		cout << "1 5 4 3 2\n";
	}
	else if (n==6) {
		cout << "1 2 4 3 6 5\n";
	}
	else if (n==7) {
		cout << "1 5 4 3 2 7 6\n";
	}
	else if (n==8) {
		cout << "1 2 4 3 8 7 6 5\n";
	}
	else if (n==9) {
		cout << "1 5 2 3 8 7 6 9 4\n";
	}
	else if (n==10) {
		cout << "1 5 2 3 8 7 6 4 10 9\n";
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

