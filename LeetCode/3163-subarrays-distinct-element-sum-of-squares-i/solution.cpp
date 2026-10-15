class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> vals;
        for (int i=0; i<n; i++) {
            if (!vals.empty()) vals.clear();
            for (int j=i; j>=0; j--) {
                vals.insert(nums[j]);
                ans += pow(vals.size(), 2);
            }
        }
        return ans;
    }
};
