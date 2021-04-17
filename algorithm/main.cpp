#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>


using namespace std;


int N, K, M;
int len[50],list[50];


int main(){
	int C; cin>>C;
	while(C--){
		vector<vector<double>> P(N,vector<double>(N));
		cin>>N>>K>>M;
		for(int i=0;i<N;i++)scanf("%d",len+i);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%lf",&P[j][i]);
		for(int i=0;i<N;i++)scanf("%d",list+i);
		
	}
	return 0;
}