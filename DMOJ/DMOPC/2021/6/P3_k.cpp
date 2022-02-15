#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
typedef pair<int, int> pi;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for (auto& a : x)

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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pi>> a(n, vector<pi>(m));
	queue<pi> que;
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			a[i][j].sec = 0;
			cin >> a[i][j].fir;
			if (a[i][j].fir) que.push({i, j});
		}
	}

	vi dx = {0, 0, -1, 1};
	vi dy = {-1, 1, 0, 0};
	while (!que.empty()) {
		pi node = que.front();
		que.pop();
		if (a[node.fir][node.sec].sec == k) continue;
		FOR (d, 0, 4) {
			if (node.fir + dx[d]<0 || node.fir + dx[d]>=n || node.sec + dy[d]<0 || node.sec + dy[d]>=m) continue;
			int curVal = a[node.fir + dx[d]][node.sec + dy[d]].fir;
			int curDist = a[node.fir + dx[d]][node.sec + dy[d]].sec;
			if (((a[node.fir][node.sec].sec + 1 < curDist) || (a[node.fir][node.sec].sec + 1 == curDist && a[node.fir][node.sec].fir < curVal)) || curVal == 0) {
				que.push({node.fir + dx[d], node.sec + dy[d]});
				a[node.fir + dx[d]][node.sec + dy[d]].fir = a[node.fir][node.sec].fir;
				a[node.fir + dx[d]][node.sec + dy[d]].sec = a[node.fir][node.sec].sec + 1;
			}
		}
	}

	trav (i, a) {
		trav (j, i) {
			cout << j.fir << ' ';
		}
		cout << nl;
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

