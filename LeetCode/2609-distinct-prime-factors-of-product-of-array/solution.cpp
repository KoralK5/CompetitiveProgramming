class Solution {
    vector<int> spf;
    void calc(int n=1000) {
        spf.resize(n+1);
        iota(spf.begin(), spf.end(), 0);
        for (int i=2; i<=n; i++) {
            if (spf[i] != i) continue;
            for (int j=i; j<=n; j+=i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        if (spf.empty()) calc();
        unordered_set<int> primes;
        for (int i : nums) {
            while (i > 1) {
                primes.insert(spf[i]);
                i /= spf[i];
            }
        }
        return primes.size();
    }
};
