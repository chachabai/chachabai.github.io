#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e4+2;
int f[N];
void init() {
	for (int a = 2; a * a < N ; ++a){
		for (int b = 2; a * a + b * b < N; ++b){
			for(int c = 2+ abs(a-b); a * a + b * b + c * c < N &&  c <= a + b - 2; ++c){
				++f[a*a+b*b+c*c];
			}
		}
	}
}
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	init();
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cout<<f[2*i]<<endl;
	}
	return 0;
}