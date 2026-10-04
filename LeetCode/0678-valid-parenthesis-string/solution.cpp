class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        deque<int> stars, lefts;
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c == '*') stars.push_back(i);
            else if (c == '(') lefts.push_back(i);
            else {
                if (!lefts.empty()) lefts.pop_back();
                else if (!stars.empty()) stars.pop_front();
                else return false;
            }
        }
        while (!lefts.empty() && !stars.empty()) {
            if (stars.back() < lefts.back()) return false;
            stars.pop_back();
            lefts.pop_back();
        }
        return lefts.empty();
    }
};
