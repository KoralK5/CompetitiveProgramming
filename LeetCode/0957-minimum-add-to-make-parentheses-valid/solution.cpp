class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') open++;
            else open--;
            if (open < 0) {
                ans++;
                open = 0;
            }
        }
        return ans + open;
    }
};
