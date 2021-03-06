#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int w, n;
	cin>>w;
	cin>>n;
	vector<int> clubs(n);
	for (int i=0; i<n; i++) {
		cin>>clubs[i];
	}
	
	vector<int> dp(w+1, 5281);
	dp[0] = 0;
	for (int i=0; i<=w; i++) {
		for (int j=0; j<n; j++) {
			if (clubs[j] + i <= w && dp[i]+1<dp[i+clubs[j]]) {
				dp[i+clubs[j]] = dp[i]+1;
			}
		}
	}
	
	if (dp[w]==5281) {
		cout<<"Roberta acknowledges defeat.";
	}
	else {
		cout<<"Roberta wins in "<<dp[w]<<" strokes.";
	}
}

