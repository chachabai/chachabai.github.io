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
		int c[10] = {};
		for (int i = 0; i < n; ++i) {
			std::string a;
			std::cin >> a;
			++c[a.back()-'0'];
		}
		std::vector<int> q;
		for (int i = 0; i < 10; ++i) if(c[i]) q.emplace_back(c[i]);
		std::sort(q.begin(), q.end());
		if (q.size() < 5) {
			std::cout << n << std::endl;
		} else if (q.size() == 5) {
			std::cout << n - q[0] << std::endl;
		} else {
			int qb = q.back();
			q.pop_back();
			int tot = 1, r = 0;
			for (auto &x : q) tot *= 5;
			for (int i = 0; i < tot; ++i) {
				int c[5] = {qb}, j = i;
				for (auto &x : q) {
					c[j % 5] += x;
					j /= 5;
				}
				r = std::max(r, *std::min_element(c,c + 5));
			}
			std::cout << n - r << std::endl;
		}
	}
	return 0;
}