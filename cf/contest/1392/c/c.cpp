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
		int a[n + 1];
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		LL r = 0;
		for (int i = n - 1; i > 0; --i) {
			if (a[i] > a[i + 1]) {
				r += a[i] - a[i + 1];
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}