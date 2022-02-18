#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q; cin>>n>>q;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];

	int t, j;
	for (int i=0; i<q; i++) {
		cin>>t;
		for (j=0; j<n; j++) {
			if (t%a[j]) {
				break;
			}
		}
		cout<<((j!=n)?j+1:-1)<<'\n';
	}
}
