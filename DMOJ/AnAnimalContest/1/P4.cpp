#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n, q; cin>>n>>q;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];

	int l, r, j;
	float x, val;
	unordered_map<float, bool> seen;
	for (int i=0; i<q; i++) {
		cin>>l>>r>>x;
		for (j=l-1; j<r; j++) {
			val = x/a[j];
			if (seen[a[j]] && val!=a[j]) {
				break;
			}
			else {
				seen[val] = true;
			}
		}
		cout<<((j==r)?"NO\n":"YES\n");
		seen.clear();
	}
}

