#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a;
	float r;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a;
		for (float i=a; i>0; i--) {
			r = sqrt(i);
			if (r == (int)r) {
				cout<<r<<'\n';
				break;
			}
		}
	}
}
		
