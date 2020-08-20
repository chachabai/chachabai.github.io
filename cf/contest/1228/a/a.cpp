#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	auto f = [](int n){
		int c[10]={};
		while(n){
			if(++c[n%10]>1) return false;
			n/=10;
		}
		return true;
	};
	int x,y;
	cin>>x>>y;
	for(int i=x;i<=y;++i){
		if(f(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}

