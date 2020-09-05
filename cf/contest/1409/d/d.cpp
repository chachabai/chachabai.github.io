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
		int s;
		std::string a;
		std::cin >> a >> s;
		int t = 0, id = 0;
		while(t <= s && id < a.size()) {
			t += a[id] - '0';
			++id;
		}
		if (t <= s) {
			std::cout << 0 << std::endl;
		} else {
			while (id > 0 && t >= s) {
				--id;
				t -= a[id] - '0';
			}
			LL r = 0;
			for (int i = id; i < a.size(); ++i) {
				r = 10 * r + ('9' - a[i]);
			}
			std::cout << r + 1 << std::endl;
		}
	}
	return 0;
}