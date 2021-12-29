#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	for (int t=0; t<T; t++) {
		string n;
		int k;
		cin>>n;
		cin>>k;
		vector<int> rem;

		int i=0;
		while (k>0 && i<n.size()-1) {
			int f = stoi(&n[i]);
			int s = stoi(&n[i+1]);
			if (f>=s) {
				n.erase(n.begin()+i);
				rem.push_back(f);
				k--;
			}
			else {
				i++;
			}
		}
			
		cout<<n<<" ";
		sort(rem.begin(), rem.end());
		for (int i : rem) {
			cout<<i;
		}
		cout<<'\n';
	}
}
