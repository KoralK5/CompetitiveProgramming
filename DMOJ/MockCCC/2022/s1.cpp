#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		if (a==b && c==a)
			cout<<"YES";
		else if (a>=c) {
			a-=c;
			if (a!=0)
				cout<<((a%2==0)?"YES":"NO");
			else
				cout<<((b%2==0)?"YES":"NO");
		} else {
			cout<<"NO";
		}
	}
}
