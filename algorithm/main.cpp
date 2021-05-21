#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int N;

int isTarget(double cStart, double cEnd, double tStart, double tEnd){
	if(cStart<cEnd){
		if(cStart<tStart && tStart<=cEnd &&!(tStart<tEnd&&tEnd<=cEnd)){
			return 1;
		}
	}
	else{
		if(tStart<=cEnd&&tStart<tEnd&&cEnd<tEnd){
			return 1;
		}else if(tStart>cStart&&tStart>tEnd&&cEnd<tEnd)return 1;
	}
	return 0;
}

int solve(vector<pair<double,pair<double,double>>> arr){
	sort(arr.begin(), arr.end(),greater<pair<double,pair<double,double>>>());
	vector<pair<double,double>> rIndex(N);
	
	double theta1, theta2; double x, y;
	for(int i=0;i<N;i++){ //Radian calculation
		if(arr[i].first >= 16.0) return 1; //Whole covering exception
		
		x = arr[i].second.first; y = arr[i].second.second;

		theta1 = acos(x / -8.0);
		if(asin(y/8)<0)theta1 = 2*M_PI - theta1;
		theta2 = 2*asin(arr[i].first / 16.0);

		rIndex[i].first = theta1 - theta2 + (theta1-theta2<0?2*M_PI:0);//A starting point
		rIndex[i].second = theta1 + theta2 - (theta1+theta2>=2*M_PI?2*M_PI:0);//A ending point
		//printf("##%lf %lf %lf %lf %lf %lf\n",arr[i].second.first, arr[i].second.second, rIndex[i].first/M_PI, rIndex[i].second/M_PI, theta1/M_PI, theta2/M_PI);
	}
	
	double tR, cStart, cEnd, tStart, tEnd, max, mS, mE, INF = 2e10;int count;
	for(int i=0;i<N;i++){  //Total iteration
		count = 1; cStart = rIndex[i].first; cEnd = rIndex[i].second; tR = cEnd - cStart + (cStart>cEnd?2*M_PI:0);
		while(1){
			int findFlag = 0;
			max = INF;
			for(int j=0;j<N;j++){ //Searching for the maximum next circle
				if(i==j)continue;
				tStart = rIndex[j].first; tEnd = rIndex[j].second;
				if(isTarget(cStart,cEnd,tStart,tEnd)){
					if(max == INF) {max = tEnd; findFlag = 1; mS = tStart; mE = tEnd;}
					else if(cEnd<max){
						if(tEnd > max || tEnd < cEnd) {max = tEnd; findFlag = 1; mS = tStart; mE = tEnd;}
					}else{
						if(tEnd > max && tEnd < cEnd) {max = tEnd; findFlag = 1; mS = tStart; mE = tEnd;}
					}
				}
			}
			if(!findFlag) break;
			count++;
			tR += mE - cEnd + (mE<cEnd?2*M_PI:0);
			//printf("##%lf %lf %lf %lf %lf\n", tR/M_PI, mS/M_PI, mE/M_PI, cStart/M_PI, cEnd/M_PI);
			cStart = mS; cEnd = mE;
			if(tR >= 2*M_PI) return count;
		}		
	}
	return -1; //If fail
}

int main(){
	/*printf("%d",isTarget(1.529255*M_PI, 0.270745*M_PI, 1.560777*M_PI, 1.720349*M_PI));
	return 0;*/
	int T;cin>>T;
	while(T--){
		cin>>N;vector<pair<double, pair<double,double>>> arr(N);
		for(int i=0;i<N;i++)scanf("%lf%lf%lf",&arr[i].second.second,&arr[i].second.first, &arr[i].first);
		int temp = solve(arr);
		if(temp==-1)cout<<"IMPOSSIBLE"<<endl;
		else cout<<temp<<endl;
	}return 0;
}