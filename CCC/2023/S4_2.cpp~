#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
#define ll long long
#define llu unsigned llu
#define F first
#define S second

typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
vector <iii> g;
vi par;

int fnd(int x){
    if (x == par[x])
        return x;
    par[x] = fnd(par[x]);
    return par[x];
}

void onion(int a, int b){
    par[fnd(a)] = par[fnd(b)];
}

int main() {
    int n, m;
    cin>>n>>m;
    
	int i;
    ll ans = 0;
    for (i = 0; i<n; i++)
        par.push_back(i);
    
	for (int i=0; i<m; i++) {
		ll a,b,w,l; cin >> a >> b >> w >> l;
		g.push_back(iii(l, ii(a-1, b-1)));
	}
    sort(g.begin(), g.end());
            
    for(i = 0; i<m; i++){
        if (fnd(g[i].S.F) != fnd(g[i].S.S)){
            ans += g[i].F;
            onion(g[i].S.F, g[i].S.S);
        }
    }
                    
    cout<<ans<<endl;
                    
    return 0;
}
