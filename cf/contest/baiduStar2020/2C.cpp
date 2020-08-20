#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a[101][11];
		for (int i = 0, x; i < n; ++ i) {
			std::cin >> x;
			for (int j = 0, t, p; j != x; ++j) {
				std::cin >> t >> p;
				a[t][p].emplace_back(i);
			}
		}
		bool v[n] = {1};
		for (int t = 1; t < 101; ++t) {
			for (int p = 1; p < 11; ++p) {
				bool flag = false;
				for (auto &x: a[t][p]) flag |= v[x];
				for (auto &x: a[t][p]) v[x] |= flag;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) if (v[i]) ++cnt;
		for (int i = 0; i < n; ++i) if (v[i]) {
			--cnt;
			std::cout << i + 1 << (" \n"[cnt == 0]);
		}
	}
	return 0;
}