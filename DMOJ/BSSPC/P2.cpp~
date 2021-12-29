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

int N, K, Q;
int x, y; 

int value(int a, int b) {
	return (a - 1) * N + b;
}

void update(vi rotation) {
	// rotate counter clockwise
	float x1=rotation[0], y1=rotation[1], x2=rotation[2], y2=rotation[3];
	x1=N-x1; x2=N-x2; y1=N-y1; y2=N-y2;
	if (x1<=x && x2>=x && y1<=y && y2>=y) {
		if (x-x1<=(x2-x1)/2 && y-y1<=(y2-y1)/2) {
			x = x2-(x-x1);
			y = y2-(y-y1);
		}
		else if (x-x1>=(x2-x1)/2 && y-y1>=(y2-y1)/2) {
			x = x1+(x2-x);
			y = y1+(y2-y);
		}
		else if (x-x1<=(x2-x1)/2 && y-y1>=(y2-y1)/2) {
			x = x2-(x-x1);
			y = y1+(y2-y);
		}
		else if (x-x1>=(x2-x1)/2 && y-y1<=(y2-y1)/2) {
			x = x1+(x2-x);
			y = y1-(y2-y);
		}
	}
}

void solve() {
	// clockwise > v
	//           ^ <
	cin>>N>>K>>Q;
	vector<vi> rotations(K, vi(4));
	FOR (i, 0, K) {
		cin>>rotations[i][0]>>rotations[i][1]>>rotations[i][2]>>rotations[i][3];
	}
	FOR (q, 0, Q) {
		cin>>x>>y;
		FOR (i, 0, K) {
			update(rotations[i]);
		}
		cout<<value(y, x)<<nl;
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

