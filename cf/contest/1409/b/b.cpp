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
		int a, b, x, y, n;
		std::cin >> a >> b >> x >> y >> n;
		auto f = [](int a, int b, int x, int y, int n) -> LL{
			int t = std::min(n, a - x);
			n -= t;
			a -= t;
			b = std::max(b - n, y);
			return 1LL * a * b;
		};
		std::cout << std::min(f(a, b, x, y, n), f(b, a, y, x, n)) << std::endl;
		// get max val
		// if (a > b) {
		// 	std::swap(a, b);
		// 	std::swap(x, y);
		// }
		// int t = std::min(std::min(b - a, n), b - y);
		// b -= t;
		// n -= t;
		// if (n == 0) {
		// 	std::cout << 1LL * a * b << std::endl;
		// } else if (b == y) {
		// 	a = std::max(a - n, x);
		// 	std::cout << 1LL * a * b << std::endl;
		// } else {
		// 	if (x < y) std::swap(x, y);
		// 	if ((a - x) * 2 <= n) {
		// 		a = x;
		// 		n -= a - x;
		// 		b = std::max(b - n, y);
		// 	} else {
		// 		std::cout << 1LL * (a - n / 2) * (a - (n + 1) / 2) << std::endl;
		// 	}
		// }
	}
	return 0;
}