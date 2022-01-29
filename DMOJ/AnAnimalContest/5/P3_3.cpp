/*
ID: Koral Kulacoglu
TASK: test
LANG: C++                 
(sorry bill XD)
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
const int MX = 2e5+5; 

vector<pi> bp[MX]; // difficulty : v

int ans[MX], s[MX], n, k;

void dfs(int u, int l, int r){
    if(r > k) return;

    ans[u] = r-l+1;
	int size = sz(bp[u]);

    if(size == 1){
        dfs(bp[u][0].sec, l, r);
    }

	else if(size == 2) {
        int split = (bp[u][0].fir + bp[u][1].fir)/2;
        int upidx = upper_bound(s+l, s+r+1, split)-s;
        dfs(bp[u][0].sec, l, upidx-1);
        dfs(bp[u][1].sec, upidx, r);
    }

	else if(size >= 3){
        bp[u].pb({INT_MAX, -1});
        for (int i = 0; i+1 < size; i++) {
            int splithigh = ((ll)bp[u][i].fir + (ll)bp[u][i+1].fir)/2;
            int splitlow, left, right;
            if (i == 0) {
				splitlow = 0;
				left = l;
			}
            else {
                splitlow = (bp[u][i-1].fir + bp[u][i].fir)/2;
                left = upper_bound(s+l, s+r+1, splitlow)-s;
            }
            right = upper_bound(s+l, s+r+1, splithigh)-s;
            dfs(bp[u][i].sec, left, right-1);
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1, a, b, d; i < n; i++){
        cin >> a >> b >> d;
        bp[a].pb({d, b});
    }

    for(int i = 1; i <= k; i++) cin >> s[i];
    sort(s+1, s+k+1);

    for(int i = 1; i <= n; i++) sort(all(bp[i]));

    dfs(1, 1, k);

	FOR (i, 1, n+1) {
		cout << ans[i];
		if (i!=n) cout << ' ';
	}
	cout << nl;

    return 0;
}
