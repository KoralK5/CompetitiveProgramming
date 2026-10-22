class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int ans = n;
        int i = find(nums.begin(), nums.end(), 0) - nums.begin();
        if (nums[(i+1)%n] == 1) {
            for (int j=0; j<n; j++) if (nums[(i+j)%n] != j) return -1;
            ans = min(ans, i);
            ans = min(ans, 2 + n - i);
            return ans;
        }
        for (int j=0; j<n; j++) if (nums[(i-j+n)%n] != j) return -1;
        for (int j=0; j<n; j++) {
            int ni = (i - j + n) % n;
            int curAns = j + (n - ni);
            ans = min(ans, curAns);
        }
        return ans;
    }
};
