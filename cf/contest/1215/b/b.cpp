#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	cin>>n;
	bool flag = 1;
	vector<int> p(1),np;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		if(x<0) flag = !flag;
		if(flag) p.emplace_back(i);
		else np.emplace_back(i);
	}
	LL cp=0,cnp=0;
	for(auto &x:p){
		cp+=lower_bound(p.begin(),p.end(),x)-p.begin();
		cnp+=lower_bound(np.begin(),np.end(),x)-np.begin();
	}
	for(auto &x:np){
		cp+=lower_bound(np.begin(),np.end(),x)-np.begin();
		cnp+=lower_bound(p.begin(),p.end(),x)-p.begin();
	}
	cout<<cnp<<" "<<cp<<endl;
	return 0;
}

