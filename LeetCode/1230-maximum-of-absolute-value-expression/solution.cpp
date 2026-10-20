/*

max(arr1[i] - arr1[j], arr1[j] - arr1[i]) + max(arr2[i] - arr2[j], arr2[j] - arr2[i]) + max(i - j, j - i)


max(
    +(arr1[i] + arr2[i] + i) -(arr1[j] + arr2[j] + j),
    -(arr1[i] + arr2[i] + i) +(arr1[j] + arr2[j] + j)
)

*/

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), ans = 0;
        for (int a : {1, -1}) {
            for (int b : {1, -1}) {
                int mx = -1e9, mn = 1e9;
                for (int i=0; i<n; i++) {
                    int v = a * arr1[i] + b * arr2[i] + i;
                    mx = max(mx, v);
                    mn = min(mn, v);
                }
                ans = max(ans, mx - mn);
            }
        }
        return ans;
    
    }
};
