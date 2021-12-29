#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n,curr;
	cin>>n;
	vector<float> m;
	for (int i=0; i<n; i++) {
		cin>>curr;
		m.push_back(curr);
	}
	int idx,op;
	float per;
	while (true) {
		cin>>op;
		if (op == 99) {
			cin>>idx;
			cin>>per;
			idx--;
			m.insert(m.begin()+idx, m[idx]*(per)/100); 
			m[idx+1] = m[idx+1]*(100-per)/100;
		}
		else if (op == 88) {
			cin>>idx;
			idx--;
			m[idx+1] += m[idx];
			m.erase(m.begin() + idx);
		}
		else if (op == 77) {
			break;
		}
	}
	for (int i:m) cout<<round(i)<<" ";
}
