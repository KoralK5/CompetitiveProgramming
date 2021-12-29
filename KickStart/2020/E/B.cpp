#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	for (int t=0; t<T; t++) {
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		if (((a+b-c)>n) || (a+b-c==1 && n>=2)) {
			cout<<"Case #"<<t+1<<": IMPOSSIBLE\n";
			continue;
		}
		else if (n==1) {
			cout<<"Case #"<<t+1<<": 1\n";
			continue;
		}
		else if (n==2) {
			if (c==2) {
				cout<<"Case #"<<t+1<<": 1 1\n";
			} else if (b==2) {
				cout<<"Case #"<<t+1<<": 2 1\n";
			} else if (a==2) {
				cout<<"Case #"<<t+1<<": 1 2\n";
			}
			continue;
		}

		vector<int> bd; bd.reserve(n);
		for (int i=0; i<a-c; i++) bd.push_back(2);
		for (int i=0; i<c; i++) bd.push_back(3);
		for (int i=0; i<b-c; i++) bd.push_back(2);
		
		int ex=n-(a+b-c);
		if (ex>0)
			bd.insert(bd.begin()+1, ex, 1);
		
		cout<<"Case #"<<t+1<<": ";
		for (int i:bd) cout<<i<<" ";
		cout<<"\n";
	}
}

