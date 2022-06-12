#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5, mod=1e9+7, MV=1e6+5;

int a[MM], b[MM];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n ;i++) cin >> a[i];
    for (int i = 1; i <= n ; ++i) {
        cin >> b[i];
    }

    vector<int> as (a+1, a+n+1), bs (b+1, b+n+1);
    as.push_back(0), bs.push_back(0);
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    bool change = 1;
    vector<pii> out;
    while(change && out.size() <= 1e4){
        change = 0;
        for(int i = 2; i <= n && out.size() <= 1e4; i++){
            if(a[i-1] > a[i] || b[i-1] > b[i]){
                change = 1;
                out.push_back({i-1, i});
                swap(a[i-1], a[i]);
                swap(b[i-1], b[i]);
            }
        }
    }

    bool sorted = 1;
    for(int i = 1; i <= n; i++){
        if(b[i] < b[i-1] || a[i] < a[i-1]) sorted = 0;
    }

    if(!sorted){
        cout << -1 << "\n";
    } else{
        cout << out.size() << "\n";
		for (auto xy : out) {
            cout << xy.first << " " << xy.second << "\n";
        }
    }

    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
