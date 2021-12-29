#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n; cin>>n;
	stack<int> l, m, r;
	for (int i=1; i<=n; i++) {
		r.push(i);
	}
	// size factorial
	int moves=0;
	while (l.size() < n) {
		if (m.size()==0) {
			for (int i=0; i<r.size()-1; i++) {
				m.push(r.top());
				r.pop();
				cout<<"1 2\n";
				moves++;
			}
			l.push(r.top());
			r.pop();
			cout<<"1 3\n";
			moves++;
		}
		else {
			for (int i=0; i<m.size()-1; i++) {
				r.push(m.top());
				m.pop();
				cout<<"2 1\n";
				moves++;
			}
			l.push(m.top());
			m.pop();
			cout<<"2 3\n";
			moves++;
		}
	}
	cout<<moves;
}
