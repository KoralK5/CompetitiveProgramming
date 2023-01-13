#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T,n=0,a,b;
	vector<pair<int,int>> r;
	cin>>T;
	for (int t=0; t<T; t++) {
		cin>>a>>b;
		n = max(n, b);
		r.push_back(make_pair(a,b));
	}

	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
	    }
	}

	vector<int> primes;
	for (int i=0; i<is_prime.size(); i++) {
		if (is_prime[i]) primes.push_back(i);
	}

	for (auto rg : r) {
		int ans=0;
		int a=rg.first, b=rg.second;
		int idx = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
		while (idx < primes.size()) {
			if (primes[idx] > b) break;
			ans += primes[idx];
			idx++;
		}
		cout<<ans<<endl;
	}
}
