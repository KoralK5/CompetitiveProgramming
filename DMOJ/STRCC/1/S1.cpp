#include <iostream>
using namespace std;

const int mod = 1e5-4;

int main() {
	int t,a,b;
	cin>>t;
	for (int i=0; i<t; i++) {
		cin>>a>>b;
		cout<<(a*b*(a-b))%mod<<endl;
	}
}

