#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

float distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

float area(float a, float b, float c, float s) {
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
	int n;
	cin>>n;
	vector<int> xs(n);
	vector<int> ys(n);
	for (int i=0; i<n; i++) {
		cin>>xs[i]>>ys[i];
	}
	float md=0;
	float a,b,c,s,A,d;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				a = distance(xs[i], ys[i], xs[j], ys[j]);
				b = distance(xs[i], ys[i], xs[k], ys[k]);
				c = distance(xs[k], ys[k], xs[j], ys[j]);
				s = (a+b+c)/2;

				float t1,t2,t3;
				t1 = pow(a,2)+pow(b,2)-pow(c,2);
				t2 = pow(c,2)+pow(b,2)-pow(a,2);
				t3 = pow(a,2)+pow(c,2)-pow(b,2);

				if (t1<0||t2<0||t3<0||s==0) {
					d = max(a,max(b,c));
					md=max(md,d);
				} else {
					A = area(a,b,c,s);
					d = (a*b*c)/(2*A);
					md = max(md,d);
				}
			}
		}
	}
	cout<<fixed<<setprecision(2)<<md;
}

