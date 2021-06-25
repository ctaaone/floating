#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory.h>

using namespace std;


typedef struct HINTSTRUCT{
	int y; int x; int dir; int sum;
} HINTSTRUCT;

vector<vector<int>> board;
vector<HINTSTRUCT> HINT;
int hintMap[20][20][2];

int N, Q;


inline int getSum(int i){return hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x000000FF;}
inline int getCur(int i){return (hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x0000FF00)>>8;}
inline int getLeft(int i){return (hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x00FF0000)>>16;}
inline int setSum(int i, char value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFFFFFF00;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=(value);}
inline int setCur(int i, char value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFFFF00FF;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=(value)<<8;}
inline int setLeft(int i, char value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFF00FFFF;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=(value)<<16;}

int min(int a, int b){
	return a<b?a:b;
}
int max(int a, int b){
	return a>b?a:b;
}

pair<int, int> getNextCoor(){
	int minBlank = 2e9, nextHINT;
	for(int i=0;i < HINT.size(); i++)
		if(getLeft(i)>0 && getLeft(i) < minBlank){
			minBlank = getLeft(i);
			nextHINT = i;
		}
	
	int Y = HINT[nextHINT].y, X = HINT[nextHINT].x, dir = HINT[nextHINT].dir;
	if(dir == 1) Y++;
	else X++;
	while(board[Y][X] != 0){
		if(dir == 1) Y++;
		else X++;
	}
	return make_pair(Y,X); 
}

bool isOver(){
	for(int i=0; i<HINT.size(); i++)
		if(getLeft(i) > 0) return false;
	return true;
}

bool checkNum(int NUM, int y, int x){
	int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
	for(int dir = 0; dir<4 ; dir++){
		int Y = y + dy[dir], X = x + dx[dir];
		while(Y>=0 && Y<N && X>=0 && X<N && board[Y][X] != -1){
			if(board[Y][X] == NUM) return false;
			Y += dy[dir]; X += dx[dir];
		}
	}
	return true;
}

pair<int, int> getProperNum(int y, int x){
	int hintnum[2] = {hintMap[y][x][0], hintMap[y][x][1]};
	for(int i=0;i<2;i++)
		if(getLeft(hintnum[i]) == 1) {
			int ret = getSum(hintnum[i]) - getCur(hintnum[i]);
			if(ret<1||ret>9) return make_pair(1,0);
			return make_pair(ret, ret+1);
		}

	int minR = 1;
	for(int i=0;i<2;i++){
		int temp = getSum(hintnum[i]) - getCur(hintnum[i]);
		if(temp/getLeft(hintnum[i]) > 9) return make_pair(1,0);
		temp -= 9*(getLeft(hintnum[i]) - 1);
		minR = max(temp , minR);
	}
	return make_pair(minR, 10);
}
void print(){
	for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d ",board[i][j]);
			}
			printf("\n");
	}
}

bool solve(){
	if(isOver()) return true;
	int nextY, nextX; pair<int, int> nextCoor;
	nextCoor = getNextCoor();
	nextY = nextCoor.first; nextX = nextCoor.second;
	pair<int, int> pnum = getProperNum(nextY, nextX);
	//printf("##%d, %d\n", pnum.first, pnum.second);
	//print();
	for(int NUM = pnum.first; NUM < pnum.second ; NUM++){
		if(checkNum(NUM, nextY, nextX)){
			board[nextY][nextX] = NUM;
			for(int dir=0;dir<2;dir++){
				int hintnum = hintMap[nextY][nextX][dir];
				setCur(hintnum, getCur(hintnum) + NUM);
				setLeft(hintnum, getLeft(hintnum) - 1);
			}
			
			if(solve()) return true;

			board[nextY][nextX] = 0;
			for(int dir=0;dir<2;dir++){
				int hintnum = hintMap[nextY][nextX][dir];
				setCur(hintnum, getCur(hintnum) - NUM);
				setLeft(hintnum, getLeft(hintnum) + 1);
			}
		}	
	}
	return false;
}

void setHintMap(){
	memset(hintMap, 0, sizeof(hintMap));
	for(int i = 0; i<HINT.size() ; i++){
		int Y = HINT[i].y, X = HINT[i].x, dir = HINT[i].dir, sum = HINT[i].sum, left = 0;
		setSum(i, sum); setCur(i, 0);
		if(dir)Y++;else X++;
		while(Y<N&&X<N&&board[Y][X] != -1){
			hintMap[Y][X][dir] = i;
			left++; if(dir)Y++;else X++;
		}
	}

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