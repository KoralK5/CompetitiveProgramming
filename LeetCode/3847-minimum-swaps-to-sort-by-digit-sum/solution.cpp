class Solution {
    int digitSum(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), [&](int a, int b) {
            int da = digitSum(a);
            int db = digitSum(b);
            if (da < db) return true;
            if (da > db) return false;
            return a < b;
        });
        unordered_map<int, int> idx;
        for (int i=0; i<n; i++) idx[nums[i]] = i;
        int swaps = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == temp[i]) continue;
            swap(nums[i], nums[idx[temp[i]]]);
            swap(idx[nums[i]], idx[nums[idx[temp[i]]]]);
            swaps++;
        }
        return swaps;
    }
};
