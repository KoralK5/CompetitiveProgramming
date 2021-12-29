#include <iostream>
using namespace std;

int main() {
	int n,c,a=0;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>c;
		a^=c;
	}
	cout<<(a?a:-1);
}
