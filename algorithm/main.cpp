#include <iostream>
#include <memory.h>

inline int max(int a, int b) {return a>b?a:b;}

using namespace std;


int N,M;
int S[20][2]; //0 price 1 preference
int cache[20][21474836];


int solve(int index, int budjet){
	int &ret = cache[index][budjet]; if(ret != -1)return ret;
	int temp = budjet; ret = 0;
	//BC
	if(index == N-1)return ret = (budjet/S[index][0])*S[index][1];
	
	for(int i=0;budjet-i*S[index][0]>0;i++){
		ret = max(solve(index+1,budjet-i*S[index][0])+i*S[index][1],ret);
	}
	
	return ret;
}


int main(){
	int C;cin>>C;
	while(C--){
		cin>>N>>M;for(int i=0;i<20;i++)for(int j=0;j<21474836;j++)cache[i][j] = -1;
		for(int i=0;i<N;i++)cin>>S[i][0]>>S[i][1];
		cout<<solve(0,M/100)<<endl;
	}
	return 0;
}