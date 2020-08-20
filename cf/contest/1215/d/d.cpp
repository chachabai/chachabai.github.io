#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	string a;
	cin>>n>>a;
	int s=0,x=0,y=0;
	for(int i=0;i<n;++i){
		if(i>=n/2){
			if(a[i]=='?') ++y;
			else s-=a[i]-'0';
		}else{
			if(a[i]=='?') ++x;
			else s+=a[i]-'0';
		}
	}
	int l = -x/2*9,r=9*(y-y/2);
	auto f = [&](int x) -> bool{
		//cout<<l<<" "<<x<<" "<<r<<endl;
		return x<=r && x>=l;
	};
	if(f(s+9*(x-x/2))&&f(s-9*(y/2))){
		cout<<"Bicarp"<<endl;
	}else{
		cout<<"Monocarp"<<endl;
	}
	return 0;
}

