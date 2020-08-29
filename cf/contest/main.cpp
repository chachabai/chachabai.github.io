#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
struct Node {
    int id, val, par, ch[2];
    void init(int _id, int _val, int _par) {
        id = _id, val = _val, par = _par, ch[0] = ch[1] = 0;
    }
};
int cartesian_build(Node *tree, int n) {
    for (int i = 1; i <= n; ++i) {
        int k = i - 1;
        while (tree[k].val > tree[i].val) k = tree[k].par;
        tree[i].ch[0] = tree[k].ch[1];
        tree[k].ch[1] = i;
        tree[i].par = k;
        tree[tree[i].ch[0]].par = i;
    }
    return tree[0].ch[1];
}
int main() {
    //freopen("in","r",stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    while (std::cin >> n) {
        if (n == 0) break;
        Node tree[n + 1];
        tree[0].init(0, 0, 0);
        for (int i = 1, x; i <= n; ++i) {
            std::cin >> x;
            tree[i].init(i, x, 0);
        }
        int root = cartesian_build(tree, n);
		// 下面是求区间
		int l[n + 1], r[n + 1];
		std::function<void(int)> getinterval = [&](int x) {
			if (x == 0) return;
			if (tree[tree[x].par].ch[0] == x) {
				r[x] = tree[x].par - (tree[x].val != tree[tree[x].par].val);
				l[x] = l[tree[x].par];
			} else {
				l[x] = tree[x].par + (tree[x].val != tree[tree[x].par].val);
				r[x] = r[tree[x].par];
			}
			getinterval(tree[x].ch[0]);
			getinterval(tree[x].ch[1]);
		};
		l[root] = 1;
		r[root] = n;
		getinterval(tree[root].ch[0]);
		getinterval(tree[root].ch[1]);
		for (int i = 1; i <= n; ++i) {
			std::cout << l[i] << " " << r[i] << std::endl;
		}
    }
    return 0;
}