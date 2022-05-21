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

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fir); cerr << ","; _print(p.sec); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << "| " << #x << " = "; _print(x); cerr << " |" << endl;
#else
#define dbg(x)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 


bool isOverlap(int minS, int maxE, vector<int> interval)
{
    if (minS >= interval[1]+1 || maxE < interval[0]-1)
    {
        return false;
    }
 
    return true;
}
 
vector<vector<int>> mi(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> res;
 
    vector<bool> vis(n, false);
 
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
 
        vis[i] = true;
        int minS = intervals[i][0];
        int maxE = intervals[i][1];
 
        while (true)
        {
            int cnt = 0;
 
            for (int j = 0; j < n; j++)
            {
                if (!vis[j] && isOverlap(minS, maxE, intervals[j]))
                {
                    vis[j] = true;
                    minS = min(minS, intervals[j][0]);
                    maxE = max(maxE, intervals[j][1]);
                    cnt++;
                }
            }
 
            if (cnt == 0)
            {
                break;
            }
        }
 
        vector<int> interval = {minS, maxE};
        res.push_back(interval);
    }
 
    sort(res.begin(), res.end());
    return res;
}
 
void solve() {
	int n, q; cin >> n >> q;
	vector<vi> v(n, vi(2));
	FOR (i, 0, n) {
		cin >> v[i][0] >> v[i][1];
	}

	vector<vi> ans = mi(v);
	 vi fVal, sVal;
	 trav (i, ans) {
		 fVal.pb(i[0]);
		 sVal.pb(i[1]);
	 }

	 // binary search
	 FOR (i, 0, q) {
		 int l, r; cin >> l >> r;
		 auto idx1 = lower_bound(all(fVal), l);
		 auto idx2 = upper_bound(all(sVal), r);

		 if (idx1==fVal.end() || idx2==sVal.end()) {
			 cout << 'N' << nl;
			 continue;
		 }

		 int loc1 = idx1 - fVal.begin();
		 int loc2 = idx2 - sVal.begin();

		 if (loc1 == loc2) {
			 cout << 'Y' << nl;
		 }
		 else {
			 cout << 'N' << nl;
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

