#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
class LinkStar {
public:
	std::vector<int> head, nxt, to;
	std::vector<LL> w;
	LinkStar(int n) {
		nxt.clear();
		to.clear();
		head = std::vector<int>(n + 1, -1);
	}
	void addedge(int u, int v, LL val) {
		nxt.emplace_back(head[u]);
		head[u] = to.size();
		to.emplace_back(v);
		w.emplace_back(val);
	}
};
struct Node {
	int d;
	LL v;
	Node(int _d, LL _v) : d(_d), v(_v) {}
	bool operator<(const Node &A) const {
		return (v + 1) / 2 * d < (A.v + 1) / 2 * A.d;
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
		for (int i = 1, u, v; i < n; ++i) {
			LL w;
			std::cin >> u >> v >> w;
			diag.addedge(u, v, w);
			diag.addedge(v, u, w);
		}
		std::priority_queue<Node> a;
		bool vis[n + 1] = {};
		std::function<int(int, LL)> dfs = [&](int u, LL val) -> int {
			vis[u] = true;
			int cnt = 0;
			for (int i = diag.head[u]; ~i; i = diag.nxt[i]) {
				int v = diag.to[i];
				if (!vis[v]) cnt += dfs(v, diag.w[i]);
			}
			cnt = std::max(cnt, 1);
			s -= val * cnt;
			a.push({cnt, val});
			return cnt;
		};
		dfs(1, 0);
		int r = 0;
		while (s < 0) {
			auto [cnt, val] = a.top();
			//std::cout << cnt << " " << val << std::endl;
			s += (val + 1) / 2 * cnt;
			if(val > 1) a.push({cnt, val / 2});
			a.pop();
			++r;
		}
		print(r);
	}
	return 0;
}