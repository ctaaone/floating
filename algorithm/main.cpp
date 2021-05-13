#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int max(int a, int b){
	return a>b?a:b;
}

int solve(vector<int> arr){
	int ret = 0;
	for(int i=1;i<N;i++){
		sort(arr.begin(), arr.end(), greater<int>());
		arr[arr.size()-2] += arr.back();
		arr.pop_back();
		ret+=arr.back();		
	}
	return ret;
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>N;vector<int> arr(N);
		for(int i=0;i<N;i++)cin>>arr[i];
		cout<<solve(arr)<<endl;
	}
	return 0;
}