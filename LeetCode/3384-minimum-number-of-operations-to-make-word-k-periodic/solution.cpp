class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size(), mx = 0;
        unordered_map<string, int> freq;
        for (int i=0; i<n; i+=k) mx = max(mx, ++freq[word.substr(i, k)]);
        return n/k - mx;
    }
};
