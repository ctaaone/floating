#include <iostream>
#include <memory.h>

inline int max(int a, int b) {return a>b?a:b;}

using namespace std;

int N,M, temp;
int S[20][2];

int main(){
	int C;cin>>C;
	while(C--){
		cin>>N>>M;
		for(int i=0;i<N;i++){
			cin>>temp>>S[i][1];
			S[i][0] = temp/10;
		}
	}
	return 1;
}