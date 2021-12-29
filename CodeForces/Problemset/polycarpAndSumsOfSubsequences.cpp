#include <iostream>
using namespace std;

int main() {
	int n; cin>>n;
	int nums[7];
	for (int i=0; i<n; i++) {
		for (int j=0; j<7; j++) {
			cin>>nums[j];
		}
		cout<<nums[0]<<" "<<nums[1]<<" "<<nums[6]-nums[0]-nums[1]<<'\n';
	}
}

