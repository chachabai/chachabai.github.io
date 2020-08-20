#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    // freopen("in","r",stdin)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    LL r = a[n - 1] - a[0] + 1;
    for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
    sort(a + 1, a + n, greater<int>());
    // for(int i=0;i<n;++i) cout<<a[i]<<" \n"[i==n-1];
    for (int i = 1; i < k; ++i) {
    	r -= a[i] - 1;
    }
    cout << r << endl;
    return 0;
}
