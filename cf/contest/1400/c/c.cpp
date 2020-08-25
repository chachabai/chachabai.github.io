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
		std::string s;
		int x;
		std::cin >> s >> x;
		std::vector<int> a(s.size(), -1);
		for (int i = 0; i != s.size(); ++i) if (s[i] == '0') {
			if (i - x >= 0) a[i - x] = 0;
			if (i + x < a.size()) a[i + x] = 0;
		}
		for (auto &t : a) if (t == -1) t = 1;
		bool flag = true;
		for (int i = 0; i != s.size(); ++i) if (s[i] == '1') {
			bool t = 0;
			if (i - x >= 0 && a[i - x] == 1) t = 1;
			if (i + x < a.size() && a[i + x] == 1) t = 1;
			if (!t) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for(auto &t : a) std::cout << t;
			std::cout << std::endl;
		} else std::cout << "-1\n";
	}
	return 0;
}