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
		LL n, k;
		std::cin >> n >> k;
		std::pair<LL, LL> p[2];
		std::cin >> p[0].first >> p[0].second;
		std::cin >> p[1].first >> p[1].second;
		if (p[0] > p[1]) std::swap(p[0], p[1]);
		LL r = 0;
		if (p[0].second < p[1].first) {
			LL t = p[1].first - p[0].second;
			LL x = p[1].second - p[0].first;
			if (x * n <= k) {
				k -= x*n;
				r += (x + t) * n + 2 * k;
			} else {
				r += t;
				if (k % x < t && k > x) r += k / x * (x + t) - t + k % x * 2;
				else r += k / x * (x + t) + k % x;
			}
		} else {
			k -= (std::min(p[0].second, p[1].second) - p[1].first) * n;
			if (k > 0) {
				LL t = p[1].first - p[0].first + std::abs(p[1].second - p[0].second);
				r += std::min(k, t * n);
				k -= t * n;
				if (k > 0) r += 2 * k;
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}