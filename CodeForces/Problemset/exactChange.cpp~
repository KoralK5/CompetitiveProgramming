#include <iostream>
#include <set>
using namespace std;

int main() {
	int T, n, curr, cSum, coins; cin>>T;
	for (int t=0; t<T; t++) {
		cin>>n;
		set<int> a;
		for (int i=0; i<n; i++) {
			cin>>curr;
			a.insert(curr);
		}
		cSum = 0;
		coins = 0;
		for (int cost:a) {
			cost -= cSum;

			coins += cost/3;
			cSum += cost/3*3;
			cost %= 3;

			coins += cost/2;
			cSum += cost/2*2;
			cost %= 2;

			coins += cost;
			cSum += cost;
		}
		cout<<coins<<'\n';
	}
}


