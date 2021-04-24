#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>
#include <stdlib.h>


using namespace std;


int N, K, M;
int len[50],list[50];

void solve(vector<vector<double>>& RM, vector<vector<double>>& P){
	int k = 0;
	int next, cur;
	while(k <= K-4){ //Nomall rotation
		for(int r=0;r<N;r++){  //Next music index
			for(int c=0;c<N;c++){  //Current music index
				next = r; cur = c;
				P[(k+len[cur])%6][next] += P[k%6][cur] * RM[next][cur];
			}
		}
		for(int i=0;i<N;i++)P[(k+5)%6][i] = 0;
		k++;
	}
	while(k<K){ //Wrap-up rotation
		for(int r=0;r<N;r++){  //Next music index
			for(int c=0;c<N;c++){  //Current music index
				next = r; cur = c;
				if(k+len[cur]>K)continue;
				P[(k+len[cur])%6][next] += P[k%6][cur] * RM[next][cur];
			}
		}
		k++;
	}
	for(int i=0;i<N;i++){
		for(int j=1;j<len[N];j++)P[K%6][i] += P[(K-j+6)%6][i];
	}
}


int main(){
	int C; cin>>C;
	while(C--){
		cin>>N>>K>>M;
		vector<vector<double>> RM(N,vector<double>(N));	//Relation matrix NxN
		vector<vector<double>> P(6,vector<double>(N)); //Result matrix   6xN
		for(int i=0;i<N;i++)scanf("%d",len+i);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%lf", &RM[j][i]); //x=y symmetry
		for(int i=0;i<N;i++)scanf("%d",list+i);
		P[0][0] = 1.0;

		solve(RM, P);

		for(int i=0;i<N;i++)printf("%.8lf ", P[K%6][list[i]]);
		printf("\n");

	}
	return 0;
}