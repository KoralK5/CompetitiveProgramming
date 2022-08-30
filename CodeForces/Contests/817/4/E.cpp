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

class FenwickTree{
private:
    // Matrix to store the tree
    std::vector<std::vector<ll>> ft;

public:
    // Function to get least significant bit
    int LSB(int x){
        return x & (-x);
    }

    ll query(int x, int y){
        ll sum = 0;
        for(int x_ = x; x_ > 0; x_ = x_ - LSB(x_)){
            for(int y_ = y; y_ > 0; y_ = y_ - LSB(y_)){
                sum = sum + ft[x_][y_];
            }
        }
        return sum;
    }

    ll query(int x1, int y1, int x2, int y2){
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
    }

    void update(int x, int y, ll value){
        // also update matrix[x][y] if needed.

        for(int x_ = x; x_ < ft.size(); x_ = x_ + LSB(x_)){
            for(int y_ = y; y_ < ft[0].size(); y_ = y_ + LSB(y_)){
                ft[x_][y_] += value;
            }
        }
    }

    FenwickTree(std::vector<std::vector<ll>> matrix){
        int n = matrix.size();
        // matrix must not be empty.
        int m = matrix[0].size();
        // Initialize matrix ft
        ft.assign(m + 1, std::vector<ll> (n + 1, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                update(i + 1, j + 1, matrix[i][j]);
        }
    }
};

// for each height, store the number of widths less than it
 
void solve() {
	int n, q; cin >> n >> q;
	vector<vll> a(1001, vll(1001, 0));
	FenwickTree ft(a);
	FOR (i, 0, n) {
		ll h, w; cin >> h >> w;
		ft.update(h, w, h*w);
	}
	FOR (i, 0, q) {
		int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
		int mih = min(hs, hb);
		int miw = min(ws, wb);

		int mah = max(hs, hb);
		int maw = max(ws, wb);

		cout << ft.query(mih+1, miw+1, mah-1, maw-1) << nl;
	}
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

