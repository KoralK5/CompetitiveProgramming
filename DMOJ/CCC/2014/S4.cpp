#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}

bool isIn(int x, int y, vector<int> c) {
	return c[0]<=x && x<=c[2] && c[1]<=y && y<=c[3];
}

int main() {
	ifstream cin("S4.in");
	ofstream cout("S4.out");

	int n, t;
	cin>>n>>t;
	vector<vector<int>> glass(n, vector<int>(5)), xVals, yVals;
	for (int i=0; i<n; i++) {
		cin>>glass[i][0]>>glass[i][1]>>glass[i][2]>>glass[i][3]>>glass[i][4];
		xVals.push_back({i, glass[i][0], 0});
		xVals.push_back({i, glass[i][2], 2});
		yVals.push_back({i, glass[i][1], 1});
		yVals.push_back({i, glass[i][3], 3});
	}

	// sort x
	sort(xVals.begin(), xVals.end(), compare);

	int val;
	// compress x
	val = xVals[0][1];
	xVals[0][1] = 0;
	for (int i=1; i<n*2; i++) {
		if (xVals[i][1] > val) {
			val = xVals[i][1];
			xVals[i][1] = xVals[i-1][1] + 1;
		} else {
			xVals[i][1] = xVals[i-1][1];
		}
	}
	
	// sort y
	sort(yVals.begin(), yVals.end(), compare);

	// compress y
	val = yVals[0][1];
	yVals[0][1] = 0;
	for (int i=1; i<n*2; i++) {
		if (yVals[i][1] > val) {
			val = yVals[i][1];
			yVals[i][1] = yVals[i-1][1] + 1;
		} else {
			yVals[i][1] = yVals[i-1][1];
		}
	}

	// convert
	int mx=0, my=0;
	vector<vector<int>> cGlass = glass;
	for (int i=0; i<n*2; i++) {
		cGlass[xVals[i][0]][xVals[i][2]] = xVals[i][1];
		cGlass[yVals[i][0]][yVals[i][2]] = yVals[i][1];
		mx = max(mx, xVals[i][1]);
		my = max(my, yVals[i][1]);
	}
	
	// psa
	int tint, area=0;
	for (int i=0; i<=mx; i++) {
		for (int j=0; j<=my; j++) {
			tint = 0;
			for (int k=0; k<n; k++) {
				if (isIn(i, j, cGlass[k])) {
					tint += cGlass[k][4];
				}
			}
			if (tint == t) {
				area++;
			}
		}
	}
	cout<<area;
}
