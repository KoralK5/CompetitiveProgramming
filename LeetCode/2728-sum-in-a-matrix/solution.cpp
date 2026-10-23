class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        for (auto& i : nums) sort(i.begin(), i.end());
        int score = 0;
        for (int i=0; i<m; i++) {
            int cur = 0;
            for (int j=0; j<n; j++) cur = max(cur, nums[j][i]);
            score += cur;
        }
        return score;
    }
};
