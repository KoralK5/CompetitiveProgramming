#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a=0,b=0;
	int n;
	cin>>n;
	for (int i=0; i<n; i++) {
		int p;
		cin>>p;
		if (a<b) {
			a+=p;
		} else {
			b+=p;
		}
	}
	cout<<abs(a-b);
}
