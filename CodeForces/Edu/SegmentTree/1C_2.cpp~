#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005], k, l, r;
pair<int, int> st[400005];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first) return a;
    if(b.first < a.first) return b;
    return {a.first, a.second+b.second};
}

void build(int node, int left, int right) {
    if(left == right) st[node] = {a[left], 1};
    else {
        int mid = (left+right)/2;
        build(2*node, left, mid);
        build(2*node+1, mid+1, right);
        st[node] = combine(st[2*node], st[2*node+1]);
    }
}

void update(int node, int left, int right, int x, int y) {
    if(left == right) st[node] = {y, 1};
    else {
        int mid = (left+right)/2;
        if(x <= mid) update(2*node, left, mid, x, y);
        else update(2*node+1, mid+1, right, x, y);
        st[node] = combine(st[2*node], st[2*node+1]);
    }
}

pair<int, int> query(int node, int left, int right, int x, int y) {
    if(x > right || left > y) return {INT_MAX, 0};
    if(left >= x && y >= right) return st[node];
    int mid = (left+right)/2;
    pair<int, int> s1 = query(2*node, left, mid, x, y);
    pair<int, int> s2 = query(2*node+1, mid+1, right, x, y);
    return combine(s1, s2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--) {
        cin >> k >> l >> r, ++l;
        if(k == 1) update(1, 1, n, l, r);
        else {
            pair<int, int> ans = query(1, 1, n, l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return 0;
}
