#include <iostream>

using namespace std;

long long N, M;

int solve(){
	int curR = 100*M/N;
	long long s = 0, e = 2000000000, h = (s+e)/2;
	while(s+1<e){
		if((h+M)*100/(N+h) >= curR+1) e = h;
		else s = h;
		h = (s+e)/2;
	}
	if((s+M)*100/(N+s) >= curR+1) return s;
	else if((e+M)*100/(N+e) >= curR+1) return e;
	return -1;
}

int main(){
	//freopen("input.txt","r",stdin);
	int T;cin>>T;
	while(T--){
		cin>>N>>M;
		cout<<solve()<<endl;
	}
	return 0;
}