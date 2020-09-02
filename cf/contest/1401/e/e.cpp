#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
const int N = 1e6;

struct TreeArray {
	std::vector<LL> s;
	TreeArray() {}
	TreeArray(int n) {
		s.resize(n);
	}
	int lowbit(int n) {
		return n & (-n);
	}
	void add(int id, int p) {
		while (id < s.size()) {
			s[id] += p;
			id += lowbit(id);
		}
	}
	LL sum(int id) {
		LL r = 0;
		while (id) {
			r += s[id];
			id -= lowbit(id);
		}
		return r;
	}
};

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> la, ra;
	for (int i = 0; i < n; ++i) {
		int lx, rx, y;
		std::cin >> y >> lx >> rx;
		if (lx == 0) la.push_back({rx, y});
		else ra.push_back({lx, y});
	}
	sort(la.begin(), la.end());
	sort(ra.begin(), ra.end());
	std::vector<std::tuple<int, int, int>> b(m);
	for (auto &[x, ly, ry] : b) std::cin >> x >> ly >> ry;
	sort(b.begin(), b.end());
	LL r = 1;
	TreeArray A(N + 1);
	for (auto &[x, y] : la) {
		A.add(y + 1, 1);
		if (x == N) ++r;
	}
	//std::cout << A.sum(100) << std::endl;
	int lid = 0, rid = 0;
	for (auto &[x, ly, ry] : b) {
		while (lid < la.size() && la[lid].first < x) {
			A.add(la[lid].second + 1, -1);
			++lid;
		}
		while (rid < ra.size() && ra[rid].first <= x) {
			A.add(ra[rid].second + 1, 1);
			++rid;
		}
		r += A.sum(ry + 1);
		if (ly != 0) r -= A.sum(ly);
		else if (ry == N) ++r;
	}
	std::cout << r << std::endl;
	return 0;
}