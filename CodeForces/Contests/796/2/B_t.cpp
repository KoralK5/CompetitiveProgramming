#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define setpre(x,d) fixed<<setprecision(d)<<x

#define pb push_back
#define mp make_pair

#define PI 3.141592653589793
#define MOD 1000000007
typedef long long int ll;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll o=0;
    for(ll i=0;i<n;i++)
        if(v[i]%2==1) 
            o++;
    if(o>0)
    {
        cout<<n-o<<endl;
    }
    else
    {
        ll ans=INT_MAX;
        for(ll i=0;i<n;i++)
        {
            ll temp=v[i];
            ll cnt=0;
            while(temp%2==0)
            {
                temp/=2;
                cnt++;
            }
            ans=min(ans,cnt);
        }
        cout<<ans+n-1<<endl;
    }
}

int main()
{
    IOS;
    ll t; cin>>t;
    while(t--)
        solve();
    return 0;
}
