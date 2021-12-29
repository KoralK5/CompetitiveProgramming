#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int w, n;
	cin>>w;
	cin>>n;
	vector<int> coins(n);
	for (int i=0; i<n; i++) {
		cin>>coins[i];
	}
	
	vector<int> dp(w+1, 5281);
	dp[0] = 0;
	for (int i=0; i<=w; i++) {
		for (int j=0; j<n; j++) {
			if (coins[j] + i <= w && dp[i]+1<dp[i+coins[j]]) {
				dp[i+coins[j]] = dp[i]+1;
			}
		}
	}
	cout<<dp[w];
}
