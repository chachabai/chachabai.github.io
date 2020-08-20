#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n, r = 0;
	cin >> n;
	for (int i = 1, x; i <= n; ++i) {
		cin>> x;
		if((i&1) && (x&1)) ++r;
	}
	cout << r << endl;
	return 0;
}