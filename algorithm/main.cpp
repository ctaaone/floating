#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

typedef struct HINTSTRUCT{
	int y; int x; int dir; int sum;
} HINTSTRUCT;

vector<vector<int>> board;
vector<HINTSTRUCT> HINT;

int N, Q;

int min(int a, int b){
	return a<b?a:b;
}

pair<int, int> getNextCoor(){
	int minBlank = 2e9, nextHINT;
	for(int i=0;i < HINT.size(); i++){
		int num = 0, Y = HINT[i].y, X = HINT[i].x;
		while(board[Y + (HINT[i].dir == 1?1:0)][X + (HINT[i].dir == 0?1:0)]==0){
			num++;
			if(HINT[i].dir == 1) Y++;
			else X++;
		}
		if(num < minBlank){
			minBlank = num;
			nextHINT = i;
		}
	}


	///
}

void solve(){

}

int main(){
	freopen("input.txt", "r", stdin);
	int T;cin>>T;
	while(T--){
		for(int i=0;i<board.size();i++)board[i].clear(); board.clear(); HINT.clear();
		
		cin>>N;
		for(int i=0;i<N;i++){
			int tempINT; vector<int> tempVector;
			for(int j=0;j<N;j++){
				scanf("%d",&tempINT); if(tempINT == 1) tempINT = -1; tempVector.push_back(tempINT);
			}
			board.push_back(tempVector);
		}
		cin>>Q;
		for(int i=0;i<Q;i++){
			HINTSTRUCT tempHINT;
			scanf("%d%d%d%d", &tempHINT.y, &tempHINT.x, &tempHINT.dir, &tempHINT.sum);
			HINT.push_back(tempHINT);
		}
		
	}
	return 1;
}