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
		int x[3];
		std::cin >> x[0] >> x[1] >> x[2];
		std::sort(x, x + 3);
		int r = 3000, n = 1000;
		for (int a = 0, ma = (n + x[1] - 1) / x[1]; a <= ma; ++a) {
			int mb = n - a * x[1] > 0 ? (n - a * x[1] + x[2] - 1) / x[2] : 0;
			for (int b = 0; b <= mb;  ++b) {
				int c1 = 0, c2 = 0;
				if (n - a * x[0] > 0) c1 = (n - a * x[0] + x[2] - 1) / x[2];
				if (n - b * x[0] > 0) c2 = (n - b * x[0] + x[1] - 1) / x[1];
				if (n - a* x[1] - b * x[2] > 0) {
					if (c1 == c2) r = std::min(r, a + b + c1);
				} else {
					r = std::min(r, a + b + std::min(c1, c2));
				}
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}