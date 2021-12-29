#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T,c;
	vector<int> n;
	cin>>T;
	for (int t=0; t<T; t++) {
		cin>>c;
		if (c==0 && n.size() > 0) {
			n.pop_back();
		} else {
			n.push_back(c);
		}
	}
	int s=0;
	for (int i : n) {
		s += i;
	}
	cout<<s;
}

