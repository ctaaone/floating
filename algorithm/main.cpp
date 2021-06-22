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
int hintMap[20][20][2];

int N, Q;

int min(int a, int b){
	return a<b?a:b;
}

pair<int, int> getNextCoor(){
	int minBlank = 2e9, nextHINT;
	for(int i=0;i < HINT.size(); i++){
		int num = 0, Y = HINT[i].y, X = HINT[i].x;
		if(HINT[i].dir == 1) Y++;
		else X++;
		
		while(Y<N && X<N && board[Y][X] != -1){
			if(board[Y][X] == 0)num++;
			if(HINT[i].dir == 1) Y++;
			else X++;
		}

		if(num != 0 && num < minBlank){
			minBlank = num;
			nextHINT = i;
		}
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
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(board[i][j] == 0)return false;
	return true;
}

bool checkNum(int NUM, int y, int x){
	int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}, overFlagH = 1, overFlagV = 1;
	for(int dir = 0; dir<4 ; dir++){
		int Y = y + dy[dir], X = x + dx[dir];
		while(Y>=0 && Y<N && X>=0 && X<N && board[Y][X] != -1){
			if(board[Y][X] == 0) {
				if(dir%2 == 0) overFlagV = 0;
				else overFlagH = 0;
			}
			if(board[Y][X] == NUM) return false;
			Y += dy[dir]; X += dx[dir];
		}
	}

	if(overFlagV == 1){
		int sum = 0, curY = y - 1, curX = x;
		while(board[curY][curX] != -1)curY--;
		int hintSum = hintMap[curY][curX][1];
		while(curY<N && board[curY][curX] != -1){
			sum += (board[curY][curX] == 0?NUM:board[curY][curX]); curY ++ ;
		}
		if(sum != hintSum)return false;
	}
	if(overFlagH == 1){
		int sum = 0, curY = y, curX = x - 1;
		while(board[curY][curX] != -1)curX--;
		int hintSum = hintMap[curY][curX][0];
		while(curX<N && board[curY][curX] != -1){
			sum += (board[curY][curX] == 0?NUM:board[curY][curX]); curX ++ ;
		}
		if(sum != hintSum){cout<<sum<<" "<<hintSum<<endl;return false;}
	}
	return true;
}


bool solve(){
	if(isOver()) return true;
	int nextY, nextX; pair<int, int> nextCoor;
	nextCoor = getNextCoor();
	nextY = nextCoor.first; nextX = nextCoor.second;
	for(int NUM = 1; NUM < 10 ; NUM++){
		if(checkNum(NUM, nextY, nextX)){
			board[nextY][nextX] = NUM;
			if(solve()) {cout<<"#";return true;}
			board[nextY][nextX] = 0;
		}
	}
	return false;
}

void setHintMap(){
	for(int i = 0; i<HINT.size() ; i++)
		hintMap[HINT[i].y][HINT[i].x][HINT[i].dir] = HINT[i].sum;
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