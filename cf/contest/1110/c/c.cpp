#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n,r;
		cin>>n;
		auto f = [](int n){
			return n == (n&-n);
		};
		if(f(n+1)){
			r = 1;
			for(int i=2;i*i<=n;++i){
				if(n%i==0){
					r = n/i;
					break;
				}
			}
		}else{
			r = 0;
			while(n){
				r = 2*r+1;
				n>>=1;
			}
		}
		cout<<r<<endl;
	}
	return 0;
}

