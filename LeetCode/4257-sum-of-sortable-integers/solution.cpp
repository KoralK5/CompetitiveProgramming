class Solution {
    pair<int, int> isValid(span<int> nums, int k) {
        bool peaked = false;
        int fst, prev = 0, mn = 1e9, mx = -1e9;
        for (int& num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
            if (prev == 0) fst = num;
            if (num < prev) {
                if (peaked) return {-1, -1};
                peaked = true;
            }
            prev = num;
        }
        if (peaked && fst < prev) return {-1, -1};
        return {mn, mx};
    }
    bool isSortable(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0;
        for (int i=0; i<n; i+=k) {
            auto [curMin, curMax] = isValid(span(nums.data() + i, k), k);
            if (curMin == -1 || curMin < mx) return false;
            mx = curMax;
        }
        return true;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k=1; k<=n; k++) ans += (!(n % k) && isSortable(nums, k)) * k;
        return ans;
    }
};
