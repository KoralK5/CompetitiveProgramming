class Solution {
    int MOD = 1e9 + 7;
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32, 0);
        for (int i : nums) {
            for (int j=0; j<32; j++) bits[j] += (i >> j) & 1;
        }
        long long ans = 0;
        for (int i=0; i<k; i++) {
            long long cur = 0;
            for (int j=31; j>=0; j--) {
                cur <<= 1;
                if (bits[j]) {
                    cur++;
                    bits[j]--;
                }
            }
            ans += cur * cur;
            ans %= MOD;
        }
        return ans;
    }
};
