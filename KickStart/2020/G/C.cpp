#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int w, n, ans;
vector<int> l;

float f(float i) {
	float sm=0;
	for (int lock:l)
		sm+=min(abs(lock-i), abs(n+i-lock));
	return sm;
}
	
int optimize() {
	ans=0;
	float m=0,d=0;
	for (int it=0; it<1000; it++) {
		d = (f(m+1)-f(m))*0.01 + d*0.9;
		m -= d;
		if (m > n)
			m-=n;
	}
	return round(m);
}

int main() {
	int T;
	cin>>T;
	for (int t=0; t<T; t++) {
		cin>>w>>n;
		for (int i=0; i<w; i++) {
			int curr;
			cin>>curr;
			l.push_back(curr);
		}
		cout<<"Case #"<<t+1<<": "<<optimize()<<"\n";
		l.clear();
	}
}
