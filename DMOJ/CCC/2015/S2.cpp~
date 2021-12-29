#include <iostream>
#include <vector>
using namespace std;

int main() {
	int j,a;
	cin>>j>>a;
	vector<char> jer(j);
	for (int i=0; i<j; i++) {
		cin>>jer[i];
	}
	
	int ans=0,jn;
	char size;
	for (int i=0; i<a; i++) {
		cin>>size>>jn;
		if (jer[jn-1] != 'x') {
			if (size == 'S') {
				ans++;
				jer[jn-1] = 'x';
			} else if (size == 'M' && jer[jn-1] != 'S') {
				ans++;
				jer[jn-1] = 'x';
			} else if (size == 'L' && jer[jn-1] == 'L') {
				ans++;
				jer[jn-1] = 'x';
			}
		}
	}
	cout<<ans;
}

