#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
const LL M = 1e9 + 7;

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
		int n;
		std::cin >> n;
		LinkStar A(n);
		for (int i = 1, x, y; i < n; ++i) {
			std::cin >> x >> y;
			A.addedge(x, y);
			A.addedge(y, x);
		}
		int d[n + 1];
		bool vis[n + 1] = {};
		std::function<int(int)> dfs = [&](int u) -> int {
			vis[u] = true;
			d[u] = 1;
			for (int i = A.head[u]; ~i; i = A.nxt[i]) {
				if (int v = A.to[i]; !vis[v]) {
					d[u] += dfs(v);
				} 
			}
			return d[u];
		};
		dfs(1);
		std::vector<LL> r;
		for (int i = 2; i <= n; ++i) {
			r.emplace_back(LL(d[i]) * (n - d[i]));
		}
		int m;
		std::cin >> m;
		std::vector<LL> p(m);
		for (auto &x : p) std::cin >> x;
		if (r.size() > p.size()) {
			std::vector<LL> tmp(r.size() - p.size(), 1);
			p.insert(p.end(), tmp.begin(), tmp.end());
		}
		std::sort(r.begin(), r.end());
		std::sort(p.begin(), p.end());
		LL s = 1;
		while (r.size() < p.size()) {
			s = s * p.back() % M;
			p.pop_back();	
		}
		p.back() = p.back() * s % M;
		LL ans = 0;
		for (int i = 0; i != r.size(); ++i) {
			ans += r[i] * p[i] % M;
		}
		std::cout << ans % M << std::endl;
	}
	return 0;
}