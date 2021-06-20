#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, best;
vector<string> member;
vector<vector<string>> food;
vector<vector<int>> edible;

bool isOver(vector<int> canEat){
	for(int i=0;i<canEat.size();i++)
		if(canEat[i] == 0) return false;
	return true;
}

vector<int> cook(int foodIndex, vector<int> canEat){
	vector<string> list = food[foodIndex];

	for(int i=0;i<list.size();i++){
		for(int j=0;j<member.size();j++)
			if(member[j] == list[i]){
				canEat[j] = 1; break;
			}
	}
	return canEat;
}

void calculEadible(){
	edible.resize(member.size());
	for(int i=0;i<food.size();i++){
		vector<string> list = food[i];

		for(int j=0;j<list.size();j++){
			for(int l=0;l<member.size();l++){
				if(member[l] == list[j]){
					edible[l].push_back(i);
					break;
				}
			}
		}
	}
}

int min(int a, int b){
	return a>b?a:b;
}

void solve(int cur, int num, vector<int> canEat){
	if(num >= best) return;
	if(cur == member.size()) return;
	if(isOver(canEat)){
		best = num; return;
	}
	if(canEat[cur] == 1){solve(cur + 1, num, canEat);return;}
	
	vector<int> eatList = edible[cur];
	for(int i=0; i < eatList.size(); i++)
		solve(cur + 1, num + 1, cook(eatList[i], canEat));

}

int main(){
	//freopen("input.txt","r",stdin);
	int T; cin>>T;
	
	while(T--){
		best = (int)2e9; member.clear(); for(int i=0;i<food.size();i++)food[i].clear(); food.clear();
		for(int i=0;i<edible.size();i++)edible[i].clear(); edible.clear();
		
		cin>>N>>M;
		for(int i=0;i<N;i++){
			string temp;
			cin>>temp; member.push_back(temp);
		}
		for(int i=0;i<M;i++){
			int L; cin>>L;
			vector<string> tempv;
			string temp;
			for(int l=0;l<L;l++){
				cin>>temp; tempv.push_back(temp);
			}
			food.push_back(tempv);
		}

		calculEadible();
		vector<int> canEat(member.size(), 0);
		solve(0, 0, canEat);
		cout<<best<<endl;
	}
	return 0;
}