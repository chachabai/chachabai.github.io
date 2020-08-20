#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int l,r,d;
	cin >> l >> r >> d;
	cout << r/d-(l-1)/d << endl;
	return 0;
}