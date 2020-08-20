#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
class LinkStar {
public:
	std::vector<int> head, nxt, to, c;
	std::vector<LL> w;
	LinkStar(int n) {
		nxt.clear();
		to.clear();
		head = std::vector<int>(n + 1, -1);
	}
	void addedge(int u, int v, LL val, int cost) {
		nxt.emplace_back(head[u]);
		head[u] = to.size();
		to.emplace_back(v);
		w.emplace_back(val);
		c.emplace_back(cost);
	}
};
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		LL s;
		std::cin >> n >> s;
		LinkStar diag(n);
		for (int i = 1, u, v, c; i < n; ++i) {
			LL w;
			std::cin >> u >> v >> w >> c;
			diag.addedge(u, v, w, c - 1);
			diag.addedge(v, u, w, c - 1);
		}
		std::vector<std::tuple<int, int, LL>> a;
		bool vis[n + 1] = {};
		std::function<int(int, LL, int)> dfs = [&](int u, LL val, int cost) -> int {
			vis[u] = true;
			int cnt = 0;
			for (int i = diag.head[u]; ~i; i = diag.nxt[i]) {
				int v = diag.to[i];
				if (!vis[v]) cnt += dfs(v, diag.w[i], diag.c[i]);
			}
			cnt = std::max(cnt, 1);
			s -= val * cnt;
			a.push_back({cost, cnt, val});
			return cnt;
		};
		dfs(1, 0, 0);
		std::vector<LL> q[2];
		for (auto [cost, cnt, val] : a) {
			while (val) {
				q[cost].emplace_back((val + 1) / 2 * cnt);
				val >>= 1;
			}
		}
		std::sort(q[0].begin(), q[0].end(), std::greater<>());
		std::sort(q[1].begin(), q[1].end(), std::greater<>());
		int r = 1e9;
		for (auto &x : q[0]) s += x;
		for (int i = 0, j = q[0].size(); i <= q[1].size(); ++i) {
			while (j > 0 && s - q[0][j - 1] >= 0) {
				s -= q[0][--j];
			}
			if (s >= 0) r = std::min(r, 2 * i  + j);
			if (i != q[1].size()) s += q[1][i];
		}
		print(r);
	}
	return 0;
}