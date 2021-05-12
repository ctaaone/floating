#include <iostream>
#include <vector>

using namespace std;

int N, INF = (int)2e9;

int max(int a, int b){
	return a>b?a:b;
}

int solve(vector<int> arr, int total){
	if(total==1) return 0; //BC
	int ret = INF;
	for(int i=0;i<total;i++){
		for(int j=0;j<total;j++){
			if(i==j)continue;

		}
	}
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>N;vector<int> arr(100);
		for(int i=0;i<N;i++)cin>>arr[i];
		cout<<solve(arr,N)<<endl;
	}
	return 0;
}