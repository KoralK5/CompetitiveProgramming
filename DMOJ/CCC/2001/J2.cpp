#include <iostream>
using namespace std;

int main() {
	int x,m,n;
	bool c=true;
	cin>>x>>m;
	for (int i=0; i<m; i++) {
		n = (x*i)%m;
		if (n==1) {
			cout<<i;
			c=false;
		}
	}
	if (c) {
		cout<<"No such integer exists.";
	}
}
