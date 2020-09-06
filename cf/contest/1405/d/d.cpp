#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
class LinkStar {
public:
	std::vector<int> head, nxt, to;
	LinkStar(int n) {
		nxt.clear();
		to.clear();
		head = std::vector<int>(n + 1, -1);
	}
	void addedge(int u, int v) {
		nxt.emplace_back(head[u]);
		head[u] = to.size();
		to.emplace_back(v);
	}
};

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, a, b, da, db;
		std::cin >> n >> a >> b >> da >> db;
		LinkStar A(n);
		for (int i = 1, u, v; i < n; ++i) {
			std::cin >> u >> v;
			A.addedge(u, v);
			A.addedge(v, u);
		}
		std::vector<int> d(n + 1);
		auto bfs = [&](int s) {
			std::fill(d.begin(), d.end(), -1);
			std::queue<int> q;
			q.push(s);
			d[s] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int i = A.head[u]; ~i; i = A.nxt[i]) {
					int v = A.to[i];
					if (d[v] == -1) {
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}
			return std::max_element(d.begin(), d.end()) - d.begin();
		};
		int c = bfs(a);
		if (db <= 2 * da || d[b] <= da) {
			std::cout << "Alice\n";
		} else {
			c = bfs(c);
			std::cout << (d[c] <= 2 * da ? "Alice" : "Bob") << std::endl;
		}
	}
	return 0;
}