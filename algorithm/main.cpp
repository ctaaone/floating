#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int N;

int isTarget(int cStart, int cEnd, int tStart, int tEnd){
	if(cStart<cEnd){
		if(cStart<tStart && tStart<=cEnd &&!(tStart<tEnd&&tEnd<=cEnd)){
			return 1;
		}
	}
	else{
		if(tStart<=cEnd || tStart>cStart){
			if(tStart<tEnd){
				if(!(tStart<tEnd&&tEnd<=cEnd))return 1;
			}else if(cEnd<tEnd){
				return 1;
			}
		}
	}
	return 0;
}

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
	
	double tR, cStart, cEnd, tStart, tEnd, max;int count;
	for(int i=0;i<N;i++){  //Total iteration
		tR = 0; count = 1; cStart = rIndex[i].first; cEnd = rIndex[i].second;
		while(1){
			int findFlag = 0;
			tR += cEnd - cStart + (cStart>cEnd?2*M_PI:0);
			if(tR >= 2*M_PI) return count;
			max = cEnd;
			for(int j=0;j<N;j++){ //Searching for the maximum next circle
				tStart = rIndex[j].first; tEnd = rIndex[j].second;
				if(isTarget(cStart,cEnd,tStart,tEnd)){
					if(max == cEnd) {max = tEnd; findFlag = 1; cStart = tStart; cEnd = tEnd; }
					else if(cEnd<max){
						if(tEnd > max || tEnd < cEnd) {max = tEnd; findFlag = 1; cStart = tStart; cEnd = tEnd; }
					}else{
						if(tEnd > max && tEnd < cEnd) {max = tEnd; findFlag = 1; cStart = tStart; cEnd = tEnd;}
					}
				}
			}
			if(!findFlag) break;
			count++;
		}		
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