// https://www.luogu.com.cn/problem/U122053?contestId=31675
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const LL M = 998244353;
const int N = 1e6 + 2;
int head[N], val[N], cnt, nxt[2 * N], to[2 * N];
bool w[2 * N];
void init() {
	cnt = -1;
	memset(head, -1, sizeof (head));
	memset(val, -1, sizeof (val));
}
void addedge(int u, int v, bool flag) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	w[cnt] = flag;
}

// 此题BFS更好，不过DFS也能过
std::pair<int, int> dfs(int u, int flag) {
	val[u] = flag;
	int r1 = 1, r2 = flag;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (val[v] != -1) {
			if (val[v] != (val[u] ^ w[i])) return {-1, 0};
		} else {
			auto [vr1, vr2] = dfs(v, val[u] ^ w[i]);
			if (vr1 == -1) return {-1, 0};
			r1 += vr1;
			r2 += vr2;
		}
	}
	return {r1, r2};
}

std::pair<int, int> bfs(int iu, int iflag) {
	std::queue<std::pair<int, int>> q;
	q.push({iu, iflag});
	int r1 = 0, r2 = 0;
	while (!q.empty()) {
		auto [u, flag] = q.front();
		q.pop();
		if (val[u] != -1) continue;
		val[u] = flag;
		++r1;
		r2 += flag;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (val[v] != -1) {
				if (val[v] != (val[u] ^ w[i])) return {-1, 0};
			} else q.push({v, val[u] ^ w[i]});
		}
	}
	return {r1, r2};
}

LL powMod(int n) {
	LL r = 1, x = 2;
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1; x = x * x % M;
	}
	return r;
}

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	init();
	int n;	
	std::cin >> n;
	for (int i = 1, x; i <= n; ++i) {
		bool flag;
		std::cin >> x >> flag;
		addedge(i, x, !flag);
		addedge(x, i, !flag);
	}
	int now = 0, mx = 0, mi = 0;
	for (int i = 1; i <= n; ++i) if (val[i] == -1) {
		// auto [r1, r2] = dfs(i, 1);
		auto [r1, r2] = bfs(i, 1);
		if (r1 == -1) {
			std::cout << "No answer\n";
			return 0;
		}
		++now;
		mx += std::max(r2, r1 - r2);
		mi += std::min(r2, r1 - r2);
	}
	std::cout << powMod(now) << std::endl;
	std::cout << mx << std::endl;
	std::cout << mi << std::endl;
	return 0;
}