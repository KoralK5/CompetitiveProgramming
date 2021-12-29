#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a, a+n, greater<int>());
	long long ans=0;
	for (int i=0; i<m; i++) {
		ans += a[i];
	}
	cout<<ans;
}
