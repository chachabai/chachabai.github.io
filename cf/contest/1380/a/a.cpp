#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int cas;
	cin >> cas;
	while (cas--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int now = 1;
		while (now < n && a[now] < a[now - 1]) ++now;
		int x = now;
		while (now < n && a[now] > a[now - 1]) ++now;
		if (now == n){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << x << " " << now << " " << now + 1 << endl;
		}
	}
	return 0;
}

