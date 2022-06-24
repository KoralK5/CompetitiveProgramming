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
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define F0Rd(i, a) for (int i=(a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
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

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= rng();
        return x ^ (x >> 16);
    }
};
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

/*
9
9 2 7 3 1 6 8 4 5

*/

/*
7
5 2 7 3 1 6 4

*/

/*
5
5 2 4 3 1
*/
 
void solve() {
	int n, mn=1e9, mn2=1e9, mnidx=0, idx=0; cin >> n;
	vi a(n);
	FOR (i, 0, n) {
		cin >> a[i];
		if (a[i] < mn) {
			mn2 = mn;
			idx = mnidx;

			mn = a[i];
			mnidx = i;
		}
		else if (a[i] < mn2) {
			mn2 = a[i];
			idx = i;
		}
	}

	// choose based on second element
	if ((mnidx+1)%n != idx) {
		vi ad=a, ax(n);
		swap(ad[mnidx], ad[idx]);
		FOR (i, idx, idx+n) {
			int loc = i%n;
			ax[(i-idx)%n] = ad[loc];
		}

		vi an=a;
		swap(an[idx], an[(mnidx+1)%n]);
		vi b(n);
		FOR (i, mnidx, mnidx+n) {
			int loc = i%n;
			b[(i-mnidx)%n] = an[loc];
		}
		vi res = b;

		swap(a[mnidx], a[((idx-1==-1)?n-1:idx-1)]);
		idx--;
		if (idx == -1) idx = n-1;
		FOR (i, idx, idx+n) {
			int loc = i%n;
			b[(i-idx)%n] = a[loc];
		}
		FOR (i, 0, n) {
			if (b[i] < res[i]) {
				res = b;
				break;
			}
			if (res[i] < b[i]) break;
		}
		FOR (i, 0, n) {
			if (ax[i] < res[i]) {
				res = ax;
				break;
			}
			if (res[i] < ax[i]) break;
		}

		trav (i, res) cout << i << ' ';
		cout << nl;
	}
	else {
		vi sa = a;
		sort(all(sa));
		int swapIdx=-1, elem=-1;
		FOR (i, mnidx, mnidx+n) {
			int loc = i%n;
			if (a[loc] != sa[i-mnidx]) {
				elem = sa[i-mnidx];
				swapIdx = loc;
				break;
			}
		}
		if (swapIdx == -1) {
			trav (i, sa) cout << i << ' ';
			cout << nl;
		}
		else {
			int sp = find(all(a), elem) - a.begin();

			swap(a[sp], a[swapIdx]);

			vi b(n);
			FOR (i, mnidx, mnidx+n) {
				int loc = i%n;
				b[(i-mnidx)%n] = a[loc];
			}

			trav (i, b) cout << i << ' ';
			cout << nl;
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

