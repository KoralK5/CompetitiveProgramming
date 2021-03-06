#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<bool>> c(n, vector<bool>(m, false));
	for (int i=0; i<k; i++) {
		char d;
		int l;
		cin>>d>>l;
		l--;
		if (d=='R') {
			for (int x=0; x<m; x++)
				c[l][x] = !c[l][x];
		} else {
			for (int x=0; x<n; x++)
				c[x][l] = !c[x][l];
		}
	}

	int ans=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			ans+=c[i][j];
		}
	}
	cout<<ans;
}

