#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

void swap(double &a, double &b){
	double temp = a;
	a = b; b = temp;
}

vector<double> solve(vector<double> coe){
	vector<double> ret;

	if(coe.size() == 3){
		double a = coe[0], b = coe[1], c = coe[2];
		double one = -b / (2 * a);
		double two = sqrt(b*b-4*a*c) / (2 * a);
		ret.push_back(one - two); ret.push_back(one + two);
		sort(ret.begin(), ret.end(), less<double>());
		return ret;
	}

	vector<double> origin = coe;
	for(int i=0;i<coe.size()-1;i++)coe[i] = coe[i] * (coe.size()-i-1);
	coe.pop_back();
	coe = solve(coe);

	vector<double> section;
	section.push_back(-10);
	section.insert(section.end(), coe.begin(), coe.end());
	section.push_back(10);

	for(int i=0;i<section.size()-1;i++){
		int iter = 60;
		double s = section[i], e = section[i+1], h = (s+e)/2;
		double Y = 0, Y1 = 0;
		for(int i=0;i<origin.size();i++){
			Y += origin[i] * pow(s, (origin.size()-i-1));
			Y1 += origin[i] * pow(e, (origin.size()-i-1));
		}
		if(Y>Y1) swap(s,e);
		
		while(iter--){
			Y = 0;
			for(int i=0;i<origin.size();i++)
				Y += origin[i] * pow(h, (origin.size()-i-1));
			if(Y>0)e = h;
			else s = h;
			h = (s+e)/2;
		}
		ret.push_back(h);
	}
	sort(ret.begin(), ret.end(), less<double>());
	return ret;
}


int main(){
	//freopen("input.txt","r",stdin);
	int T;cin>>T;
	while(T--){
		vector<double> coe;
		cin>>N;for(int i=0;i<=N;i++){double temp;scanf("%lf",&temp);coe.push_back(temp);}
		vector<double> solution = solve(coe);
		for(int i=0;i<solution.size();i++)printf("%.12lf ",solution[i]);
		cout<<endl;
	}
	return 0;
}