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
		int a[n];
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		LL r = 0, now = 0;
		for (int i = 0; i < n; ++i) {
			now += a[i];
			if (now < 0) {
				r -= now;
				now = 0;
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}