#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool pal(int n) {
    string s = to_string(n);
    int sz = s.size();
    for (int i=0; i<sz/2; i++) {
        if (s[i] != s[sz-i-1]) {
            return false;
        }
    }
    return true;
}

int wheel(long n) {
    set<int> res;
    res.insert(1);
    long ws[] = {1,2,2,4,2,4,2,4,6,2,6};
    long f = 2; int w = 0;
    while (f * f <= n) {
        if (n % f == 0) {
            set<int> nRes=res;
            for (auto &i : nRes) {
                res.insert(i*f);
            }
            n /= f;
        } else {
            f += ws[w];
            w = (w == 10) ? 3 : (w+1);
        }
    }
    
    set<int> nRes=res;
    for (auto &i : nRes) {
        res.insert(i*n);
    }

    int ans=0;
    for (auto &i : res) {
        ans += pal(i);
        // if (pal(i)) cout << i << ' ';
    }

    return ans;
}

void solve() {
    long n; cin >> n;
    cout << wheel(n) << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}
