#include <iostream>
#include <memory.h>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


vector<pair<double, double>> camp;
int N;

bool isConnect(double length){
	int queue[101], next = 1, cur = 0, visited[100];
	memset(visited, 0, sizeof(visited)); visited[0] = 1; queue[0] = 0;
	while(next != cur){
		int curnum = queue[cur];
		for(int j=0;j<N;j++){
			double x1 = camp[curnum].first, x2 = camp[j].first, y1 = camp[curnum].second, y2 = camp[j].second;
			if(visited[j] == 0&&length*length >= (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)){
				queue[next++] = j; visited[j] = 1;
			}
		}
		cur++;
	}
	if(cur == N) return true;
	return false;
}

double solve(){
	double start = 0, end = 1000, half = (start + end)/2;
	while(half - start > 0.00001){
		if(isConnect(half)){
			end = half ; half = (start + end)/2;
		}else{
			start = half; half = (start + end)/2;
		}
	}
	return half;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int T;cin>>T;
	while(T--){
		cin>>N;camp.clear();
		for(int i=0;i<N;i++){
			double x, y;
			scanf("%lf%lf",&x, &y); camp.push_back(make_pair(x,y));
		}
		printf("%.2lf\n",solve());
	}
	return 0;
}