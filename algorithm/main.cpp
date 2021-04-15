#include <iostream>
#include <memory.h>

inline int max(int a, int b) {return (a)>(b)?(a):(b);}

using namespace std;

int N,M, temp;
int S[20][2];

int solve(){
	int C[201];memset(C, -1, sizeof(C));
	for(int i=0;i<=M;i++){
		int cur = i%201;
		for(int j=0;j<N;j++)
			if(i+S[j][0]>M)continue;
			else C[(cur+S[j][0])%201] = max(C[(cur+S[j][0])%201],C[cur]+S[j][1]);
	}
	int ret=0;
	for(int i=0;i<201;i++)ret = max(ret, C[i]);
	return ret;
}

int main(){
	int C;cin>>C;
	while(C--){
		cin>>N>>M; M/=100;
		for(int i=0;i<N;i++){
			cin>>temp>>S[i][1];
			S[i][0] = temp/100;
		}
		cout<<solve()<<endl;
	}
	return 1;
}