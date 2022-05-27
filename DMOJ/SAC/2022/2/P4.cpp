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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int n, m; 

template <typename T>
class Graph{
public:
    int v;
    map<T,list<pair<T,int>>>l;
    void addEdge(T u,T v,int wt,bool bidir=true){
        l[u].push_back(make_pair(v,wt));
        if(bidir){
            l[v].push_back(make_pair(u,wt));
        }
    }
    void print(){
        for(auto it=l.begin();it!=l.end();it++){
            cout<<it->first<<" -> ";
            for(auto it1=it->second.begin();it1!=it->second.end();it1++){
                cout<<"("<<it1->first<<","<<it1->second<<"),";
            }
            cout<<"\n";
        }
    }
    void dijkstra(T src){
        map <T,int>dist;
        for(auto i=l.begin();i!=l.end();i++){
            dist[i->first]=INT_MAX;
        }
        dist[src]=0;
        set<pair<int,T>>s;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p=*(s.begin());
            T node=p.second;
            int nodeDist=p.first;
            s.erase(s.begin());
            for(auto i=l[p.second].begin();i!=l[p.second].end();i++){
                if(nodeDist+i->second<dist[i->first]){
                    T dest=i->first;
                    auto f= s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest]=nodeDist+i->second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
		int ct=0;
        for(auto d=dist.begin();d!=dist.end();d++){
            // cout<<d->first<<" is located at distance of "<<d->second<<"\n";
			ct++;
			if (ct == n*m) cout << d->second << nl;
        }
    }
};

string vals(int i, int j) {
	return to_string(i) + ' ' + to_string(j);
}

void solve() {
	// dijkstra's
	cin >> n >> m;
	vector<string> a(n); FOR (i, 0, n) cin >> a[i];
	Graph<string> g;
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (i+1<n)  g.addEdge(vals(i, j), vals(i+1, j), a[i+1][j]=='C');
			if (i-1>=0) g.addEdge(vals(i, j), vals(i-1, j), a[i-1][j]=='C');
			if (j+1<m)  g.addEdge(vals(i, j), vals(i, j+1), a[i][j+1]=='C');
			if (j-1>=0) g.addEdge(vals(i, j), vals(i, j-1), a[i][j-1]=='C');
		}
	}
	g.dijkstra(vals(0, 0));
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

