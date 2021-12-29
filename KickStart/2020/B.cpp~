#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
	int n, k, p;
	cin>>n>>k>>p;
	vector<vector<int>> plates(n, vector<int>(k)), sum(n, vector<int>(k+1, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++) {
			cin>>plates[i][j];
			sum[i][j+1] = sum[i][j] + plates[i][j];
		}
	}

	vector<vector<int>> dp(n+1, vector<int>(p+1, 0));
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=p; j++) {
			for (int x=0; x<=min(j, k); x++) {
				dp[i][j] = max(dp[i][j], sum[i][x+1]+dp[i-1][j-x]);
			}
		}
	}
	return dp[n][p];
}

int main() {
	int T;
	cin>>T;
	for (int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<": "<<solve()<<'\n';
	}
}

