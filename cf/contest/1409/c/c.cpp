#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	std::string a;
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, x, y;
		std::cin >> n >> x >> y;
		int d = 1;
		for (int i = 2; i < n; ++i) {
			if ((y - x) % i == 0) d = i;
		}
		d = (y - x)/d;
		int cnt = 0;
		while (cnt < n) {
			int t = y - d * cnt;
			if (t > 0) std::cout << t << " ";
			else break;
			++cnt;
		}
		while(cnt < n) {
			++cnt;
			y += d;
			std::cout << y << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}