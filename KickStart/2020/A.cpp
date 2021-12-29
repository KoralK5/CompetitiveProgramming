#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, a, b;
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>a>>b;
		vector<int> h(a);
		for(int i=0; i<a; i++) {
			cin>>h[i];
		}
		sort(h.begin(), h.end());
		int i;
		for (i=0; i<a; i++) {
			if (b >= h[i]) {
				b -= h[i];
			} else {
				break;
			}
		}
		cout<<"Case #"<<t<<": "<<i<<'\n';
	}
}
