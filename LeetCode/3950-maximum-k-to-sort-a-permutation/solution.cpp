class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for (int i=0; i<n; i++) if (nums[i] != i) ans &= i;
        return ans == -1 ? 0 : ans;
    }
};
