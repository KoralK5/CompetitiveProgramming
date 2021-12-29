#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("outofplace.in");
	ofstream cout("outofplace.out");
	int n;
	cin>>n;
	vector<int> nums(n);
	for (int i=0; i<n; i++) {
		cin>>nums[i];
	}
	int idx, num;
	if (nums[0] > nums[1] && nums[0] > nums[2]) {
		idx = 0;
		num = nums[0];
	}
	else {
		for (int i=1; i<n; i++) {
			if (nums[i] < nums[i-1]) {
				idx = i;
				num = nums[i];
				break;
			}
		}
	}
	int ans=0, dir=(num>nums[i-1]?1:-1);
	while (true) {
		idx = idx+dir;
		if (nums[idx]>=num && num>=nums[idx-1]) {
			break;
}
