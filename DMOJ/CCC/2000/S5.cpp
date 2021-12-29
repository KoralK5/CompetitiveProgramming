#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

float distance(float x1, float y1, float x2, float y2) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
	int n;
	cin>>n;
	float field[n][2];
	for (int i=0; i<n; i++) {
		cin>>field[i][0];
		cin>>field[i][1];
	}

	float prevX=-1, prevY=-1;
	float minX=1001, minY=1001, minDist=1415, dist;
	for (int loc=0; loc<=1000; loc++) {
		for (int i=0; i<n; i++) {
			dist = distance(loc, 0, field[i][0], field[i][1]);
			if (dist < minDist) {
				minDist=dist;
				minX=field[i][0];
				minY=field[i][1];
			}
		}
		if (!(minX==prevX && minY==prevY)) {
			prevX=minX;
			prevY=minY;
			cout<<fixed<<setprecision(2)<<"The sheep at ("<<minX<<", "<<minY<<") might be eaten.\n";
		}
		minDist=1415;
		minX=1001;
		minY=1001;
	}
}
