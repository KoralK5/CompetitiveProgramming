class Solution {
    bool isValid(string& s) {
        int open = 0;
        for (char c : s) {
            if (islower(c)) continue;
            if (c == '(') open++;
            else if (open == 0) return false;
            else open--;
        }
        return open == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int maxSize = 0;
        unordered_set<string> res, seen;
        queue<string> q;
        q.push(s);
        seen.insert(s);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            int n = cur.size();
            if (n < maxSize) continue;

            if (isValid(cur)) {
                maxSize = n;
                res.insert(cur);
                continue;
            }

            for (int i=0; i<n; i++) {
                if (islower(cur[i])) continue;

                string child = cur;
                child.erase(child.begin() + i);

                if (seen.contains(child)) continue;

                q.push(child);
                seen.insert(child);
            }
        }

        vector<string> resVec(res.begin(), res.end());

        return resVec;
    }
};
