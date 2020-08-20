#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int N = 1002;
int a[N][N];
int d[N][N];
void init() {
	for(int i=1; i < N; ++i) d[i][0] = d[0][i] = i;
	for(int i = 1; i < N; ++ i) {
		for (int j = 1; j <= i; ++ j) {
			d[i][j] = d[j][i%j];
		}
	}
	for(int i = 1; i < N; ++ i) {
		for (int j = i + 1; j < N; ++ j) {
			d[i][j] = d[j][i];
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++ j) {
			a[i][j] = std::max(a[i - 1][j], a[i][j - 1]);
			if(d[i][j] == 1) ++a[i][j];
		}
	}
}

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	init();
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::cout << a[n][m] << std::endl;
	}
	return 0;
}
