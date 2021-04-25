#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>
#include <stdlib.h>


using namespace std;



int N, K, M;
int len[50],list[10];

void solve(vector<vector<double>>& RM, vector<vector<double>>& P){
	int k = 0;
	int next, cur;
	
	while(k<4){ //Initial rotation
		for(int r=0;r<N;r++){  //Next music index
			for(int c=0;c<N;c++){  //Current music index
				next = r; cur = c;
				if(k+len[cur] < 4){
					P[k+len[cur]][next] += P[k][cur] * RM[cur][next];
				}
			}
		}
		k++;
	}
	if(K<4){
		for(int i=0;i<N;i++){
			for(int j=K-1;j>=0&&len[i]>K-j;j--)P[K][i] += P[j][i];
		}
		return ;
	}
	vector<vector<double>> M(4*N, vector<double>(4*N));
	for(int i=0;i<3*N;i++)
		M[i][i+N] = 1.0;
	for(int r=3*N;r<4*N;r++){
		for(int k1=0;k1<4;k1++){
			for(int c=0;c<N;c++){
				next = r; cur = c;
				if(len[cur]+k1==4) M[r][k1*c] = P[k1][cur] * RM[cur][next];
			}
		}
	}	//M initialize
	
}


int main(){
	int C; cin>>C;
	while(C--){
		cin>>N>>K>>M;
		vector<vector<double>> RM(N,vector<double>(N));	//Relation matrix NxN
		vector<vector<double>> P(4,vector<double>(N));  //Result matrix   4xN
		for(int i=0;i<N;i++)scanf("%d",len+i);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%lf", &RM[i][j]);
		for(int i=0;i<M;i++)scanf("%d",list+i);

		solve(RM, P);


		for(int i=0;i<M;i++)printf("%.8lf ", P[K][list[i]]);
		printf("\n");

	}
	return 0;
}