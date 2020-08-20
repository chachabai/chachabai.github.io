#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int N = 2e5 + 2;
int head[N], cnt, nxt[2 * N], to[2 * N], d[N];
bool vis[N];
void init() {
	cnt = -1;
	memset(head, -1, sizeof (head));
	memset(d, 0, sizeof (d));
	memset(vis, 0, sizeof (vis));
}
void addedge(int u, int v) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		init();
		int n, m;
		std::cin >> n >> m;
		LL p[n + 1], h[n + 1];
		for (int i = 1; i <= n; ++i) std::cin >> p[i];
		for (int i = 1; i <= n; ++i) std::cin >> h[i];
		for (int i = 1, x, y; i < n; ++i) {
			std::cin >> x >> y;
			addedge(x, y);
			addedge(y, x);
			++d[x];
			++d[y];
		}
		std::set<int,std::greater<>> q;
		for (int i = 1; i <= n; ++i) {
			if (d[i] <= 1) q.insert(i);
		}
		LL good[n + 1] = {}, bad[n + 1] = {};
		bool flag = true;
		while (!q.empty()) {
			int u = *q.begin();
			vis[u] = true;
			q.erase(q.begin());
			h[u] -= good[u];
			p[u] += bad[u];
			LL x = p[u] + h[u], y =  p[u] - h[u];
			if (x < 0 || y < 0 || y % 2 == 1) {
				flag = false;
				break;
			}
			x /= 2;
			x += good[u];
			y /= 2;
			for (int i = head[u]; ~i; i = nxt[i]) if (!vis[to[i]]){
				int v = to[i];
				if (--d[v] <= 1) q.insert(v);
				good[v] += x;
				bad[v] += y;
			}
		}
		std::cout << (flag ? "YES" : "NO") << std::endl;
	}
	return 0;
}