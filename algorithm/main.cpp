#include <iostream>
#include <memory.h>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


vector<pair<double, double>> camp;
int N;

void solve();

int main(){
	freopen("input.txt", "r", stdin);
	int T;cin>>T;
	while(T--){
		cin>>N;camp.clear();
		for(int i=0;i<N;i++){
			double x, y;
			scanf("%lf%lf",&x, &y); camp.push_back(make_pair(x,y));
		}

	}
	return 0;
}