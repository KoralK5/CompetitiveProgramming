class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";
        string res(num, '0');
        int i = 0;
        while (i < num && sum) {
            int digit = min(sum, 9);
            res[i++] = '0' + digit;
            sum -= digit;
        }
        return res;
    }
};
