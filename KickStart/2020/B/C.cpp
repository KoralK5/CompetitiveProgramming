#include <iostream>
using namespace std;

string s;
int w, h, size;
int N,S,E,W;
int o;

void solve(int idx) {
	if (idx==size)
		return;
	while (o!=0) {
		if (s[idx]>='0' && s[idx]<='9') { 
			solve(idx);
		}
		else if (s[idx] == "(") {
			o++;
		}
		else if (s[idx] == ")") {
			o--;
		}
		else {

		
		


int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		cin>>s;
		size = s.length();
		w=1;h=1;
		N=0;S=0;E=0;W=0;
		o=0;
		solve(0);
		cout<<"Case #"<<i+1<<": "<<w<<" "<<h<<"\n";
	}
}

