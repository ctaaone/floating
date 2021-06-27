#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int N, M;
vector<double> plist;

bool can(double dist){
	int count = 1, cur = 0;
	for(int j=1;j<M;j++){
		if(plist[j] - plist[cur] >= dist){
			count ++; cur = j;
		}
	}
	if(count >= N) return true;
	return false;
}


double solve(){ //240 && .2
	double start = 0, end = 240, half = (start + end)/2;
	while(1){
		half = (start + end) / 2;
		if(half - start < 0.0001) return half;
		if(can(half)){
			start = half;
		}else{
			end = half;
		}
	}
}

int main(){
	//freopen("input.txt", "r",stdin);
	int T;cin>>T;
	while(T--){
		plist.clear();
		cin>>N>>M;
		for(int i=0;i<M;i++){
			double temp;scanf("%lf",&temp);plist.push_back(temp);
		}
		printf("%.2lf\n",round((solve()*100))/100);
	}
	return 0;
}