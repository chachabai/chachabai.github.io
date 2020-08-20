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
		int n, m, p;
		std::cin >> n >> m >> p;
		int r = 0;
		if (n >= m) {
			n -= m;
			++r;
			r += n / ((m * p + 99) / 100);
		}
		std::cout << r << std::endl;
	}
	return 0;
}