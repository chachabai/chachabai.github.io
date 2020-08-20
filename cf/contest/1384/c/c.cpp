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
		std::string a, b;
		std::cin >> n >> a >> b;
		std::vector<int> s[20];
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			if (flag) break;
			if (a[i] > b[i]) flag = true;
			else {
				s[a[i]-'a'].emplace_back(b[i] - 'a');
			}
		}
		if (flag) {
			std::cout << "-1\n";
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < 20; ++i) {
			if (s[i].empty()) continue;
			std::sort(s[i].begin(), s[i].end());
			int j = 0;
			while(j != s[i].size() && s[i][j] == i) ++j;
			if (j == s[i].size()) continue;
			++cnt;
			int t = s[i][j];
			while(++j != s[i].size()) s[t].emplace_back(s[i][j]);
		}
		std::cout << cnt << std::endl;
	}
	return 0;
}