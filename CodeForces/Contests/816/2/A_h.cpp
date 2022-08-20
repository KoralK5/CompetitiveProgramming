#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t;
    cin>>t;
    while (t--){
        int n, m;
        cin>>n>>m;
        if (n==1 && m==1)
          cout<<"0"<<endl;
        else{
          int mi = min(n, m);
          int ma = max(n, m);
          int res = mi + mi - 2 + ma-1 + 1;
          cout<<res<<endl;
        }

      
    }
      
}
