#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<LL> a(n);
	for (auto &x : a) std::cin >> x;
	if (n < 3) {
		std::cout << 0 << std:: endl;
		return 0;
	}
	std::sort(a.begin(), a.end());
	LL r = std::accumulate(a.begin(), a.end(), LL(-n));
	if (n >= 55) {
		std::cout << r << std::endl;
		return 0;
	}
	int c = 1;
	while (++c) {
		LL now = 1, s = 0;
		for (auto x : a) {
			s += abs(x - now);
			if (s > r) break;
			now *= c;
		}
		if (s > r) break;
		r = s;
	}
	std::cout << r << std::endl;
	return 0;
}