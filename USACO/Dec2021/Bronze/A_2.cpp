#include <iostream>
using namespace std;

string c;
int count=0;
int n;

void dfs(int l, int r, long long g, long long h, bool dir, int depth) {
	if ((g>1 && h>1) || (l<0) || (r>=n)) {
		return;
	}
	else if (depth==0) {
		dfs(l-1, r, g, h, false, depth+1);
		dfs(l, r+1, g, h, true, depth+1);
	}
	else {
		if (g==1 || h==1) count++;
		if (dir) {
			dfs(l-1, r, g+c[r]=='G', h+c[r]=='H', false, depth+1);
			dfs(l, r+1, g+c[r]=='G', h+c[r]=='H', true, depth+1);
		} else {
			dfs(l-1, r, g+c[l]=='G', h+c[l]=='H', false, depth+1);
			dfs(l, r+1, g+c[l]=='G', h+c[l]=='H', true, depth+1);
		}
	}
}

int main() {
	int g=0, h=0;
	long long ans=0;
	cin>>n;
	cin>>c;
	for (int s=1; s<n-1; s++) {
		dfs(s-1, s+1, c[s-1]=='G' + c[s]=='G' + c[s+1]=='G', c[s-1]=='G' + c[s]=='G' + c[s+1]=='G', 0, 0);
		ans += count;
		count = 0;
	}
	cout<<ans;
}
