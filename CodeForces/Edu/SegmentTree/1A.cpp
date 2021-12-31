#include <bits/stdc++.h> 
using namespace std;

struct segTree {
	int size;
	vector<long long> sums;

	void init(int n) {
		size = 1;
		while (size < n) size*=2;
		sums.assign(2*size, 0LL);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int mid = (lx + rx)/2;
		if (i < mid) {
			set(i, v, 2*x+1, lx, mid);
		}
		else {
			set(i, v, 2*x+2, mid, rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	long long sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int mid = (lx + rx)/2;
		long long lChild= sum(l, r, 2*x+1, lx, mid);
		long long rChild = sum(l, r, 2*x+2, mid, rx);
		return lChild + rChild;
	}

	long long sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

int main() {
	int n, m; cin >> n >> m;

	segTree st;
	st.init(n);

	int v;
	for (int i=0; i<n; i++) {
		cin >> v;
		st.set(i, v);
	}
	int op;
	while (m--) {
		cin >> op;
		if (op == 1) {
			int i, v; cin >> i >> v;
			st.set(i, v);
		}
		else {
			int l, r; cin >> l >> r;
			cout<<st.sum(l, r)<<'\n';
		}
	}

	return 0;
}
