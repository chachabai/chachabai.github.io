#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		string a;
		cin>>a;
		queue<int> odd,even;
		for(auto &x:a){
			if((x-'0')%2==0) even.push(x-'0');
			else odd.push(x-'0');
		}
		odd.push(11);
		even.push(10);
		vector<int> r;
		for(int i=0;i!=a.size();++i){
			if(odd.front()<even.front()){
				r.emplace_back(odd.front());
				odd.pop();
			}else{
				r.emplace_back(even.front());
				even.pop();
			}
		}
		for(auto &x:r) cout<<x;
		cout<<endl;
	}
	return 0;
}

