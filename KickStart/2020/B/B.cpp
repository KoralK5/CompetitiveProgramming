#include <iostream>
using namespace std;

typedef long long ll;

int n;
ll d;
ll x[1010];

bool works(ll k) {
	for (int i=0; i<n; i++) {
		if (k%x[i] != 0)
			k += x[i] - k % x[i];
	}
	return k <= d;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		cin>>n>>d;
		for (int j=0; j<n; j++) {
			cin>>x[j];
		}
		ll lo=0, hi=d;
		while (lo<hi) {
			ll mid = (lo+hi+1)/2;
			if (works(mid)) {
				lo=mid;
			} else {
				hi=mid-1;
			}
		}
		cout<<"Case #"<<i+1<<": "<<lo<<"\n";
	}
}

