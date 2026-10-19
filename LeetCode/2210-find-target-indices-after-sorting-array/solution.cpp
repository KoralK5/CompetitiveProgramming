class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == target) res.push_back(i);
        }
        return res;
    }
};
