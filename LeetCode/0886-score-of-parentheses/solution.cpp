class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size(), ans=0, start=0, depth=0;
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c == '(') depth++;
            else depth--;
            if (depth == 0) {
                if (i - start == 1) ans++;
                else ans += 2 * scoreOfParentheses(s.substr(start + 1, i - start - 1));
                start = i+1;
            }
        }
        return ans;
    }
};
