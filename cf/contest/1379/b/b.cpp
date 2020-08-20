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
		LL l, r, m;
		std::cin >> l >> r >> m;
		m += r-l;
		for (LL a = l; a <= r; ++a) {
			if (m >= a && m%a <= 2*(r-l)) {
				if (m%a <= (r-l)) std::cout << a << " "<< (l + m%a) <<" "<< r << std::endl;
				else std::cout << a << " " <<  r << " " << (2*r-l-m%a) << std::endl;
				break;
			}
		}
	}
	return 0;
}