#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;

struct Node {
	int id;
	int val;
	Node() {}
	Node(int _id, int _val) : id(_id), val(_val) {}
	bool operator<(const Node & A) const {
		return id - val < A.id - A.val;
	}
};
int main() {
	// freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, q;
	std::cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::vector<pii> b(q);
	for (auto &[x, y]: b) std::cin >> x >> y;
	std::sort(b.begin(), b.end(), greater<>());
	for (int i = n - 1; ~i; --i) {

	}
	return 0;
}



#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        if (a[i] > i)
            a[i] = -1;
        a[i] = i - a[i];
    }
    std::vector<std::vector<int>> dp(4 * n);
    std::function<void(int, int, int)> solve = [&](int p, int l, int r) {
        dp[p].resize(r - l + 1);
        if (r - l == 1) {
            dp[p][1] = a[l];
        } else {
            int m = (l + r) / 2;
            solve(2 * p, l, m);
            solve(2 * p + 1, m, r);
            for (int i = 0, j = 0, k = 0, s = 0; i <= r - l; ++i) {
                while (j + k < i) {
                    if (k + 1 <= r - m && dp[2 * p + 1][k + 1] <= s + j) {
                        ++k;
                    } else if (j + 1 <= m - l && dp[2 * p][j + 1] <= s) {
                        ++j;
                    } else {
                        s = std::min(j + 1 <= m - l ? dp[2 * p][j + 1] : n + 1, k + 1 <= r - m ? dp[2 * p + 1][k + 1] - j : n + 1);
                    }
                }
                dp[p][i] = s;
            }
        }
    };
    solve(1, 0, n);
    std::function<int(int, int, int, int, int, int)> query = [&](int p, int l, int r, int x, int y, int s) -> int {
        if (l >= y || r <= x) {
            return s;
        } else if (l >= x && r <= y) {
            return s + std::upper_bound(dp[p].begin(), dp[p].end(), s) - dp[p].begin() - 1;
        } else {
            int m = (l + r) / 2;
            s = query(2 * p, l, m, x, y, s);
            return query(2 * p + 1, m, r, x, y, s);
        }
    };
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        r = n - r;
        std::cout << query(1, 0, n, l, r, 0) << "\n";
    }
    return 0;
}