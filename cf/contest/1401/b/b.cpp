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
		int x1, y1, z1, x2, y2, z2;
		std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int r  = 0;
		int zy = std::min(z1, y2);
		r += 2 * zy;
		x1 -= zy;
		z2 -= x1 + z1;
		if (z2 > 0) r -= 2 * z2;
		std::cout << r << std::endl;
	}
	return 0;
}