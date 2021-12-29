#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;

	vector<string> v;
	char s;
	string temp = "";
	char _;
	cin.get(_);
	char last=' ';
	while (cin.get(s)) {
		if (s=='\n') break;
		if (s=='0') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s);
		}
		last = s;
	}
	v.push_back(temp);
	
	int val;
	int mx=0, mi=0;
	for (int i=0; i<m; i++) {
		cin>>val;
		if (val>=mx) {
			mx = val;
			mi = i;
		}
	}
	if (last=='0' && mi==m-1) {
		for (int i=0; i<v.size(); i++) {
			cout<<v[i];
		}
		cout<<'\n';
		return 0;
	}
	
	for (int i=mi+1; i<v.size(); i++) {
		cout<<v[i];
	}
	for (int i=mi; i>=0; i--) {
		cout<<v[i];
	}
	cout<<'\n';
}
