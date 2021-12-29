#include <iostream>
#include <set>
using namespace std;

int main() {
	int g, p, curr;
	set<int> d;
	cin>>g>>p;
	for (int i=0; i<p; i++) {
		cin>>curr;
		d.insert(curr);
	}
	int low = *d.upper_bound(g);
	cout<<low;
}
