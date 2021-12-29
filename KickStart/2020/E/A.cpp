#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> dp(n, 0);
		for (int j=0; j<n; j++)
			cin>>a[j];	

		for (int i=1; i<n; i++) 
			a[i-1] = a[i] - a[i-1];

		int ans=1;
		int c=1;
		for (int i=1; i<n-1; i++) {
		       if (a[i] == a[i-1]) {
				c++;
		 	} else {
				c=1;
			}
			ans=max(ans,c);
		}

		cout<<"Case #"<<i+1<<": "<<ans+1<<"\n";
	}
}
