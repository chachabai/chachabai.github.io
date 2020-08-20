#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int a,b,c,r=0;
		cin>>a>>b>>c;
		r+=min(b,c/2);
		b-=min(b,c/2);
		r+=min(a,b/2);
		cout<<3*r<<endl;
	}
	return 0;
}

