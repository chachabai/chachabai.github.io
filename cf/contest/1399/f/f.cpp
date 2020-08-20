// follow the idea of Jiangly
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
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
		std::vector<std::pair<int, int>> a(n);
		std::vector<int> v;
		for (auto &[l, r] : a) std::cin >> l >> r;
		a.push_back({1, 2e5});
		for (auto &[l, r] : a) {
			v.emplace_back(l);
			v.emplace_back(r);
		}
		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
		for (auto &[l, r] : a) {
			l = std::lower_bound(v.begin(), v.end(), l) - v.begin();
			r = std::lower_bound(v.begin(), v.end(), r) - v.begin();
		}
		std::sort(a.begin(), a.end(), [](const auto &lhs, const auto &rhs) {
			if (lhs.first == rhs.first) return lhs.second < rhs.second;
			return lhs.first > rhs.first;
		});
		int dp[n + 1] = {};
		for (int i = 0; i <= n; ++i) {
			std::vector<int> f(a[i].second + 1);
			int mx = 0, x = a[i].first - 1;
			for (int j = i - 1; j >= 0; --j) {
				if (a[j].second > a[i].second) continue;
				while (x + 1 < a[j].first) mx = std::max(mx, f[++x]);
				f[a[j].second] = std::max(f[a[j].second], dp[j] + mx);
			}
			for (auto &t : f) mx = std::max(mx, t);
			dp[i] = 1 + mx;
		}
		print(dp[n] - 1);
	}
	return 0;
}