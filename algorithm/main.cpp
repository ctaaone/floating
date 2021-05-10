#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>
#include <stdlib.h>


using namespace std;



int N, K, M;
int len[50],list[10];

vector<vector<double>> multi(vector<vector<double>> A, vector<vector<double>> B){
	int R = A.size(), C = B[0].size(), L = B.size();
	vector<vector<double>> res(R, vector<double>(C));
	for(int r=0;r<R;r++){
		for(int c=0;c<C;c++){
			for(int l=0;l<L;l++){
				res[r][c] += A[r][l] * B[l][c];
			}
		}
	}
	return res;
}

vector<vector<double>> pow(int n, vector<vector<double>> M){
	if(n == 1) return M;
	if(n%2==0){
		vector<vector<double>> temp = pow(n/2,M);	//Got wrong here
		return multi(temp, temp);
	}
	return multi(pow(n-1, M), M);
}
void printV(vector<vector<double>> &A){
	printf("\nPV\n");
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			printf("%.3lf ",A[i][j]);
		}printf("\n");
	}
}
vector<vector<double>> nMulti(vector<vector<double>> A, vector<vector<double>> B){
	int R = A.size();
	vector<vector<double>> res(B.size(), vector<double>(B[0].size()));
	for(int r=0;r<R;r++){
			for(int l=0;l<R;l++){
				res[r/N][r%N] += A[r][l] * B[l/N][l%N];
			}
	}
	return res;
}

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
			for(int j=K-1;j>=0&&K-j+1<=len[i];j--)P[K][i] += P[j][i];
		}
		return ;
	}
	vector<vector<double>> M(4*N, vector<double>(4*N)),R;
	for(int i=0;i<3*N;i++)
		M[i][i+N] = 1.0;
	for(int r=3*N;r<4*N;r++){
		for(int k1=0;k1<4;k1++){
			for(int c=0;c<N;c++){
				next = r-3*N; cur = c;	//Got wrong here
				if(len[cur]+k1==4) M[r][k1*N+c] = RM[cur][next];	//Got wrong index here
			}
		}
	}	//M initialize
	R = pow(K-3, M);
	P = nMulti(R, P);//P needs to be nomalized

	for(int i=0;i<N;i++){
		for(int j=2;j>=0&&len[i]>3-j;j--)P[3][i] += P[j][i];
	}
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

		P[0][0] = 1.0;
		solve(RM, P);


		for(int i=0;i<M;i++)printf("%.8lf ", P[(K<4?K:3)][list[i]]);
		printf("\n");

	}
	return 0;
}