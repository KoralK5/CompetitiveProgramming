class Solution {
public:
    long long maximumValue(int n, int s, long long m) {
        return s + n / 2 * m - (n - 2) / 2;
    }
};
