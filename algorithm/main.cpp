#include <vector>
#include <iostream>

using namespace std;


int N, K, maxL;
vector<int> L, M, G; // Distance, Length, Interval

int max(int a, int b){
	return a>b?a:b;
}

bool isRight(int d){
	int sum = 0;
	for(int i=0;i<N;i++){
		int start = L[i] - M[i], end = L[i];
		if(start <= K && K <= end)
			sum += (K-start) / G[i] + 1;
	}
	return sum >= K;
}

int solve(){
	int s = 0, e = maxL, h = (s + e)/2;
	while(s < e){
		if(isRight(h)){
			e = h; h = (s + e)/2;
		}else{
			s = h; h = (s + e)/2; 
		}
	}
	return h;
}

int main(){
	int T;cin>>T;
	while(T--){
		L.clear(); M.clear(); G.clear(); maxL = 0;
		cin>>N>>K;
		for(int i=0;i<N;i++){
			int tL, tM, tG;
			scanf("%d%d%d", &tL, &tM, &tG);
			maxL = max(maxL, tL);
			L.push_back(tL); M.push_back(tM); G.push_back(tG);
		}
		cout<<solve()<<endl;
	}
	return 0;
}