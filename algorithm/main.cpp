#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

int min(int a, int b){return a<b?a:b;}

int lsolve(vector<pair<double, double>>& rad, double S, double E){
	int count = 0, cFlag = 0;
	for(int i=0;i<N;i++){
		double start = rad[i].second, end = rad[i].first;
		if((start<=S||start>E)){
			if(end>=E||
		}
	}
	if(!cFlag)return 2e9;
	return count==0?(int)2e9:count;
}

int csolve(vector<pair<double, pair<double, double>>>& par){
	vector<pair<double, double>> rad(N);
	vector<pair<double, double>> nrad(N);
	double theta1, theta2;
	for(int i=0;i<N;i++){
		double x = par[i].second.first, y = par[i].second.second, r = par[i].first;
		theta1 = atan2(y, x);
		theta2 = 2*asin(r/16);
		rad[i].second = theta1-theta2; rad[i].first = theta1+theta2;
	}
	sort(rad.begin(), rad.end(), greater<pair<double, double>>());
	for(int i=0;i<N;i++){nrad[i].first = fmod(rad[i].first + 3*M_PI, 2*M_PI); nrad[i].second = fmod(rad[i].second + M_PI, 2*M_PI);}//Revese from here

	int ret = (int)2e9;
	for(int i=0;i<N;i++){
		double start = rad[i].second, end = rad[i].first;
		if(start<=0&&end>=0){
			ret = min(ret, 1 + lsolve(nrad, nrad[i].first, nrad[i].second));
		}
	}
	return ret;
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>N;vector<pair<double, pair<double, double>>> sol(N);
		for(int i=0;i<N;i++)scanf("%lf%lf%lf",&sol[i].second.second, &sol[i].second.first, &sol[i].first);
		int temp = csolve(sol);
		if(temp==(int)2e9)cout<<"IMPOSSIBLE"<<endl;
		else cout<<temp<<endl;
	}
	return 0;
}