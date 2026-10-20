class Solution {
    inline static vector<int> spf;
    unordered_map<int, int> freq;
    void precomp(int n=1e6) {
        spf.resize(n+1); iota(spf.begin(), spf.end(), 0);
        for (int i=2; i<=n; i++) {
            if (spf[i] != i) continue;
            for (int j=i; j<=n; j+=i) {
                if (spf[j] != j) continue;
                spf[j] = i;
            }
        }
    }
    unordered_map<int, int> getFactors(int x) {
        unordered_map<int, int> factorFreq;
        while (x > 1) {
            factorFreq[spf[x]]++;
            x /= spf[x];
        }
        return factorFreq;
    }
    long long getGood(unordered_map<int, int>& factorFreq, unordered_map<int, int>::iterator start) {
        long long ans = 0;
        int num = 1;
        for (auto& p : factorFreq) for (int t = 0; t < p.second; t++) num *= p.first;
        auto it = freq.find(num);
        if (it != freq.end()) ans += it->second;
        for (auto p = start; p != factorFreq.end(); p++) {
            if (p->second == 0) continue;
            p->second--;
            ans += getGood(factorFreq, p);
            p->second++;
        }
        return ans;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (spf.empty()) precomp();
        long long ans = 0;
        freq.clear();
        freq.reserve(nums2.size() * 2);
        for (int i : nums2) if (1LL * i * k <= 1e6) freq[i * k]++;
        for (int i : nums1) {
            auto factorFreq = getFactors(i);
            ans += getGood(factorFreq, factorFreq.begin());
        }
        return ans;
    }
};
