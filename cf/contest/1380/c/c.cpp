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
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n, greater<int>());
		int cur = 0, r = 0;
		for (int i = 0; i < n; ++i) {
			++cur;
			if(cur * a[i] >= x){
				++r;
				cur  = 0;
			}
		}
		cout << r << endl;
	}
	return 0;
}

