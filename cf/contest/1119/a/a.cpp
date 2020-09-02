#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	// freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (a[1] != a[n]) {
		cout << n - 1 << endl;
		return 0;
	}
	int x = 1;
	while (a[x] == a[1]) ++x;
	int r = max(x - 1, n - x);
	x = n;
	while (a[x] == a[1]) --x;
	r = max(r, max(x - 1, n - x));
	cout << r << endl;
	return 0;
}