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
	int n, k; cin>>n>>k;
	vi a(n);
	int x=0, currX;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		x ^= a[i];
	}
	float size, inc;
	bool works;
	for (int i=0; i<n; i++) {
		currX = x;
		for (int j=n-1; j>i; j--) {
			size = j-i+1;
			if ((currX==0 || size/k==1) && size>=k) {
				inc = size/k;
				works = true;
				for (int s=i; s<=j-inc; s++) {
					if (a[s] != a[s+inc]) {
						works = false;
						break;
					}
				}
				if (works) {
					cout<<inc<<nl;
					for (int s=i; s<i+inc; s++) cout<<a[s]<<" ";
					return;
				}
			}
			currX ^= a[j];
		}
		x ^= a[i];
	}
	cout<<-1;
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

