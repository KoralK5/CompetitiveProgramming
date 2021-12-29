#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	string a,b;
	unordered_map<char,int> am;
	unordered_map<char,int> bm;
	cin>>a>>b;

	for (int i=0; i<a.size(); i++) {
		am[a[i]]++;
		bm[b[i]]++;
	}

	int count=0;
	for (auto curr:am) {
		if (curr.first!='*') {
			count+=abs(am[curr.first]-bm[curr.first]);
		}
	}
	
	int ac = am['*'] + bm['*'];
	if (count==ac) {
		cout<<'A';
	} else {
		cout<<'N';
	}
}
