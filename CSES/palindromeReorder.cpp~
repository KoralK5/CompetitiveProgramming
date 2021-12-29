#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string n; cin>>n;
	int s = n.size();
	sort(n.begin(), n.end());
	vector<char> p(s);
	int count = 0;
	for (int i=0, j=0; j<s; i++, j++) {
		if (n[j] == n[j+1]) {
			p[i] = n[j];
			p[s-i-1] = n[j+1];
			j++;
		}
		else {
			if (s%2==0 || count==1) {
				cout<<"NO SOLUTION";
				return 0;
			}
			p[s/2] = n[j];
			i--;
			count++;
		}
	}
	for (char i : p) cout<<i;
}

