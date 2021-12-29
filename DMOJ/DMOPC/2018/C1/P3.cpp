#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long m;
	cin>>n>>m;
	vector<int> c(n);
	for (int i=0; i<n; i++)
		cin>>c[i];

	long long ans=0,curr=0,count=0;
	for (int i=0; i<n; i++) {
		count+=c[i];
		while (count>=m) {
			count-=c[curr];
			curr++;
		}
		ans = max(ans, i-curr+1);
	}
	cout<<ans;
}

