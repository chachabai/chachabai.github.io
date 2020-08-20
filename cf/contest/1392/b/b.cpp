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
		LL k;
		std::cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		int mx = *std::max_element(a, a + n);
		for (int i = 0; i < n; ++i) a[i] = mx - a[i];
		mx = *std::max_element(a, a + n);
		if (k %2 == 0) {
			for (int i = 0; i < n; ++i) a[i] = mx - a[i];
		}
		for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
		std::cout << std::endl;
	}
	return 0;
}