#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int q,a,b,c;
	cin>>q>>a>>b>>c;
	int count=0;
	while (true) {
		q--;
		count++;
		a++;
		if (a%35==0) q+=30;
		if (q==0) break;
	
		q--;
		count++;
		b++;
		if (b%100==0) q+=60;
		if (q==0) break;
	
		q--;
		count++;
		c++;
		if (c%10==0) q+=9;
		if (q==0) break;
	}	
	cout<<"Martha plays "<<count<<" times before going broke.";
}

