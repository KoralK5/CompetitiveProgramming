#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int q,n;
	cin>>q>>n;
	vector<int> d(n), p(n);
	for (int i=0; i<n; i++)
		cin>>d[i];

	for (int i=0; i<n; i++)
		cin>>p[i];
	
	sort(d.begin(), d.end());
	sort(p.begin(), p.end());

	int ans=0;
	if (q==1) {
		for (int i=0; i<n; i++) {
			ans += max(d[i],p[i]);
		}
	}
	else if (q==2) {
		for (int i=0; i<n; i++) {
			ans += max(d[i],p[p.size()-i-1]);
		}
	}
	cout<<ans;
}
