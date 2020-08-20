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
		string a;
		int R = 0, S = 0, P = 0;
		cin >> a;
		for (auto &c:a){
			if(c == 'R') ++P;
			else if(c == 'P') ++S;
			else ++ R;
		}
		char c = (R>S?(R>P?'R':'P'):(S>P?'S':'P'));
		for (int i = 0 ;i != a.size(); ++i) {
			cout << c;
		}
		cout << endl;
	}
	return 0;
}

