class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        stack<int> stk; stk.push(0);
        for (char c : s) {
            if (c == '(') stk.push(0);
            else if (stk.size() > 1) {
                int len = stk.top() + 2;
                stk.pop();
                stk.top() += len;
                ans = max(ans, stk.top());
            }
            else stk.top() = 0;
        }
        return ans;
    }
};
