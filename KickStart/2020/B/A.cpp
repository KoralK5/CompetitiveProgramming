#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		int n;
		cin>>n;
		int h[n];
		for (int j=0; j<n; j++) {
			cin>>h[j];
		}
		int p=0;
		for (int k=1; k<n-1; k++)
			p += (h[k]>h[k-1] && h[k]>h[k+1]);
		cout<<"Case #"<<i+1<<": "<<p<<"\n";
	}
}


