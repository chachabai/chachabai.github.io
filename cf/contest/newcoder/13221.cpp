#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<LL> f(LL n) {
	std::vector<LL> r(10, 0);
	LL now = 1;
	while (now <= n) {
		for (int i = 1; i < 10; ++i) {
			if ((i + 1) * now > n) {
				r[i] += n - i * now + 1;
				break;
			}
			for (LL j = i * now, t; j < (i + 1) * now; j = t + 1) {
				t = std::min(n / (n / j), (i + 1) * now  - 1);
				r[i] += LL(n / j) *  (t - j + 1);
			}
		}
		now *= 10;
	}
	return r;
}

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	LL l, r;
	std::cin >> l >> r;
	auto fl = f(l - 1);
	auto fr = f(r);
	for (int i = 1; i < 10; ++i) {
		std::cout << fr[i] - fl[i] << std::endl;
	}
	return 0;
}