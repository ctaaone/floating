#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int N;

int solve(vector<pair<double,pair<double,double>>> arr){
	sort(arr.begin(), arr.end(),greater<pair<double,pair<double,double>>>());
	vector<pair<double,double>> rIndex(N);
	
	double theta1, theta2;
	for(int i=0;i<N;i++){ //Radian calculation
		if(arr[i].first >= 16) return 1; //Whole covering exception
		
		theta1 = acos(arr[i].second.second / -8);
		if(asin(arr[i].second.first/8)<0)theta1 = 2*M_PI - theta1;
		theta2 = 2*asin(arr[i].first / 16);

		rIndex[i].first = theta1 - theta2 + (theta1-theta2<0?2*M_PI:0);//A starting point
		rIndex[i].second = theta1 + theta2 - (theta1+theta2>2*M_PI?2*M_PI:0);//A ending point
	}
	
	double iStart, cStart, cEnd, tStart, tEnd, max;int count = 1;
	for(int i=0;i<N;i++){  //Total iteration
		
	}
	return -1; //If fail
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>N;vector<pair<double, pair<double,double>>> arr(N);
		for(int i=0;i<N;i++)scanf("%lf%lf%lf",&arr[i].second.first,&arr[i].second.second, &arr[i].first);
		int temp = solve(arr);
		if(temp==-1)cout<<"IMPOSSIBLE"<<endl;
		else cout<<temp<<endl;
	}return 0;
}