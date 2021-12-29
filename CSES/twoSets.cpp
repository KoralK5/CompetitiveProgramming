#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> s1, s2;
	cin>>n;
	if (n*(n+1)/2%2!=0 || n<3) {
		cout<<"NO"<<endl;
	}
	else if (n%4==3) {
		cout<<"YES"<<endl;
		for (int i=n; i>0; i--) {
			s1.push_back(i);
			if (i%2==1) {
				i-=2;
			}
		}
		for (int i=n-1; i>0; i--) {
			s2.push_back(i);
			if (i%2==1) {
				i-=2;
			}
		}


		cout<<s1.size()<<"\n";
		for (int i : s1) {
			cout<<i<<" ";
		}
		cout<<"\n"<<s2.size()<<endl;
		for (int i : s2) {
			cout<<i<<" ";
		}
	}
	else {
		cout<<"YES"<<endl;
		for (int i=1; i<n; i+=4) {
			s1.push_back(i);
			s1.push_back(i+3);
			s2.push_back(i+1);
			s2.push_back(i+2);
		}
		cout<<s1.size()<<"\n";
		for (int i : s1) {
			cout<<i<<" ";
		}
		cout<<"\n"<<s2.size()<<endl;
		for (int i: s2) {
			cout<<i<<" ";
		}
	}
}
