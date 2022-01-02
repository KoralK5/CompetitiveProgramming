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
#define fir first
#define sec second
#define lbound lower_bound
#define ubound upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define gcd(a, b) __gcd(a, b)
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int qlog2(int x) {
    return 31 - __builtin_clz(x);
}
int qlog2(long long x) {
    return 63 - __builtin_clzll(x);
}
template <typename T>
struct Sparse {
	long long func(long long a, long long b) {
		return a+b;
	}
    int n;
    vector<vector<T>> sparse;

    Sparse(vector<T> &arr) {
        n = arr.size();
        sparse.assign(qlog2(n) + 1, vector<T>(n + 1, 0));
        for (int i = 0; i < n; i++) sparse[i][0] = arr[i];
        for (int j = 1; j <= qlog2(n); j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                sparse[i][j] = func(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
    }
    T minQuery(int l, int r) {
        int j = qlog2(r - l + 1);
        return func(sparse[l][j], sparse[r - (1 << j) + 1][j]);
    }
    T sumQuery(int l, int r) {
		long long sum = 0;
		for (int j = n; j >= 0; j--) {
			if ((1 << j) <= r - l + 1) {
				sum += sparse[l][j];
				l += 1 << j;
			}
		}
		return sum;
    }
};
 
void solve() {
	int n; cin >> n;
	vi arr(n, 0);
	int a, b, w;
	FOR (i, 1, n) {
		cin >> a >> b >> w;
		FOR (i, a, b+1) arr[i]+=w;
	}
	Sparse<int> sp(arr);
	int q; cin >> q;
	int l, r;
	FOR (i, 0, q) {
		cin >> l >> r;
		cout << sp.sumQuery(l, r) << nl;
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

