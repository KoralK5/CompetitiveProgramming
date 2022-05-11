//HEADER
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define all(a) begin(a), end(a)
#define sort(a) sort(all(a))

// speed up cin and cout
void setIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    set<int> ok;
    for(int i : a){
        if(freq[i] >= k){
            ok.insert(i);
        }
    }
    if(!ok.size()){
        cout << -1 << "\n";
        return;
    }
    //
    int best = 1;
    int l = a[0];
    int r = a[0];
    int prev = -1;
    int seg = 1;
    for(int i : ok){
        if(i != prev+1){
            prev = i;
            seg = 1;
        } else {
            prev = i;
            seg++;
        }
        if(seg >= best){
            best = seg;
            r = i;
            l = r-best+1;
        }
    }
    cout << l << " " << r << "\n";
}

int t;
int main(){
    setIO();
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
