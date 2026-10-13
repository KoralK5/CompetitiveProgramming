class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(nums.begin(), nums.end());
        for (long long &i : temp) i *= i;
        sort(temp.begin(), temp.end());
        long long ans = 0;
        for (int i=0; i<n/2; i++) ans -= temp[i];
        for (int i=n/2; i<n; i++) ans += temp[i];
        return ans;
    }
};
