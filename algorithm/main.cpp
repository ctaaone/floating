#include <iostream>
#include <vector>
#include <utility>

using namespace std;


typedef struct HINTSTRUCT{
	int y, x, dir, sum;
} HINTSTRUCT;
vector<HINTSTRUCT> HINT;
int hintMap[20][20][2];
inline int getSum(int i){return hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x000000FF;}
inline int getLen(int i){return (hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x0000FF00)>>8;}
inline void setSum(int i, int value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFFFFFF00;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=value;}
inline void setLen(int i, int value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFFFF00FF;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=(value<<8);}

vector<vector<int>> board;
int N, Q;

int min(int a, int b){return a<b?a:b;}
int max(int a, int b){return a>b?a:b;}

pair<int, int> getNextCoor(){
	int min=2e9, next;
	for(int i=0;i<HINT.size();i++){
		if(getLen(i)<min){
			min = getLen(i); next = i;
		}
	}
	int Y = HINT[next].y, X = HINT[next].x;
	if(HINT[next].dir == 1) Y++; else X++;
	while(Y<N&&X<N&&board[Y][X] != -1){
		if(board[Y][X] == 0) return make_pair(Y, X);
		if(HINT[next].dir == 1) Y++; else X++;
	}
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
				scanf("%d",&tempINT); if(tempINT == 0) tempINT = -1; else tempINT = 0; tempVector.push_back(tempINT);
			}
			board.push_back(tempVector);
		}
		cin>>Q;
		for(int i=0;i<Q;i++){
			HINTSTRUCT tempHINT;
			scanf("%d%d%d%d", &tempHINT.y, &tempHINT.x, &tempHINT.dir, &tempHINT.sum);
			tempHINT.y--;tempHINT.x--;
			HINT.push_back(tempHINT);
		}
		setHintMap();

		solve();
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j] == -1) printf("0 ");
				else printf("%d ",board[i][j]);
			}
			printf("\n");
		}
	}
	return 1;
}