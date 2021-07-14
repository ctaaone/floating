#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, K;
vector<int> r, c;

bool isRight(double x){
	vector<double> res(N);
	for(int i=0;i<N;i++)res[i] = c[i] * x - r[i];
	sort(res.begin(), res.end(), greater<double>());
	double sum = 0;
	for(int i=0;i<K;i++)
		sum += res[i];
	if(sum>=0) return true;
	return false;
}

double solve(){
	double s = 0, e = 1, h = (s+e)/2;
	while(e-s>1e-10){
		if(isRight(h)) e = h;
		else s = h;
		h=(s+e)/2;
	}
	return h;
}

int main(){
	//freopen("input.txt","r",stdin);
	int T;cin>>T;
	while(T--){
		cin>>N>>K;r.clear();c.clear();
		for(int i=0;i<N;i++){int tempr,tempc;scanf("%d%d",&tempr,&tempc);r.push_back(tempr);c.push_back(tempc);}
		printf("%.10lf\n", solve());
	}
	return 0;
}