#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,c;
	cin>>n>>c;
	vector<int> w(n), v(n);
	for (int i=0; i<n; i++) 
		cin>>w[i]>>v[i];

	vector<vector<int>> dp(n+1, vector<int>(c+1));
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=c; j++) {
			if (i==0 || j==0)
				dp[i][j] = 0;
			else if (w[i-1] > j) 
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
			}
		}
	cout<<dp[n][c];
}
	
