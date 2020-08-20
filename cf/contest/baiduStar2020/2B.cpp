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
		LL a[n], sa[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		std::sort(a, a + n);
		sa[0] = a[0];
		for (int i = 1; i < n; ++i) sa[i] = sa[i - 1] + a[i];
		LL r = 0;
		for (int i = 0; i < n; ++i) {
			r += (sa[n - 1] - sa[i]) - a[i] * (n - 1 - i);
		}
		std::cout << r << std::endl;
	}
	return 0;
}