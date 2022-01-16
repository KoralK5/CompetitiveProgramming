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

// sieve
vi primes;
void sieve(int n) {
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	FOR (i, 0, n) {
		if (is_prime[i]) primes.pb(i);
	}
}

void solve() {
	int n; cin >> n;
	// almost all cases can be solved with the order 1, 2, 3, 4, ..., n
	// it will only fail iff all the prime distances p[i] can jump to work for the opponent
	// so we must screw over the opponent by moving p[i] to the previous number that does not work

	// 1 or 2 can't go any lower
	if (n <= 2) {
		cout << -1 << nl;
		return;
	}

	// up to 10 works
	if (n < 10) {
		FOR (i, 1, n+1) {
			cout << i;
			if (i!=n) cout << ' ';
		}
		cout << nl;
		return;
	}

	// now figure out which numbers can't reach non-working numbers
	// if n can reach a non-working number, then it can be ordered 1, 2, 3, ..., n
	// check the reach via prime distances, otherwise n is non-working
	vector<int> a(n+1);
	FOR (i, 0, 3) a[i] = false;
	FOR (i, 3, 10) a[i] = true;
	FOR (i, 10, n+1) {
		bool works=false;
		trav (prime, primes) {
			if (prime==1) continue;
			if (prime > i) break;
			if (a[i-prime] == false) {
				a[i] = 1;
				works = true;
				break;
			}
		}
		if (!works) a[i] = 0;
	}

	if (a[n]) {
		FOR (i, 1, n+1) {
			cout << i;
			if (i!=n) cout << ' ';
		}
		cout << nl;
		return;
	}
	else {
		// find second last working point and replace that with n
		int rep=0;
		for (int i=n; i>0; i--) {
			if (a[i]) {
				rep = i;
				break;
			}
		}
		FOR (i, 1, n) {
			if (i == rep) {
				cout << n << ' ';
			}
			cout << i;
			if (i!=n-1) cout << ' ';
		}
		cout << nl;
	}
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
	sieve(MX);
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

