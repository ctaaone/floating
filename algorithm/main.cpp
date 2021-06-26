#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>

using namespace std;

typedef struct HINTSTRUCT{
	int y, x, dir, sum;
} HINTSTRUCT;
vector<HINTSTRUCT> HINT;
int hintMap[20][20][2];
int candi[46][20][1025];
inline int getSum(int i){return hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x000000FF;}
inline int getLen(int i){return (hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0x0000FF00)>>8;}
inline int getS(int i){return (hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&0xFFFF0000)>>16;}
inline void setSum(int i, int value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFFFFFF00;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=value;}
inline void setLen(int i, int value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]&=0xFFFF00FF;hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]|=(value<<8);}
inline void setS(int i, int value){hintMap[HINT[i].y][HINT[i].x][HINT[i].dir]^=((1<<value)<<16);}

inline bool inSet(int num, int i){return num & (1<<i);}

vector<vector<int>> board;
int N, Q;

int min(int a, int b){return a<b?a:b;}
int max(int a, int b){return a>b?a:b;}

void printb(int num){for(int i=1;i<=9;i++){if(inSet(num, i))printf("%d",i);else printf("0");}cout<<endl;}

pair<int, int> getNextCoor(){
	int min=2e9, next;
	for(int i=0;i<HINT.size();i++){
		if(getLen(i) > 0 && getLen(i)<min){
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

int getNumSet(int y, int x){
	int ret = 0xFFFFFFFF;
	for(int i=0;i<2;i++){
		int sum = getSum(hintMap[y][x][i]), left = getLen(hintMap[y][x][i]), set = getS(hintMap[y][x][i]);
		printf("#%d %d %d\n",sum, left, set);
		printb(candi[sum][left][set]);
		ret &= candi[sum][left][set];
	}
	cout<<endl;
	return ret;
}

bool isOver(){
	for(int i=0;i<HINT.size();i++)
		if(getLen(i) > 0) return false;
	return true;
}


bool solve(){
	if(isOver()) return true;
	pair<int, int> next = getNextCoor();
	int nextY = next.first, nextX = next.second;
	int numset = getNumSet(nextY, nextX);
	printf("#%d %d %d\n\n\n\n", nextY, nextX, numset);
	int hintnum[] = {hintMap[nextY][nextX][0], hintMap[nextY][nextX][1]};
	for(int i = 1; i < 10 ; i++){
		if(inSet(numset, i)){
			for(int dir=0;dir<2;dir++){setLen(hintnum[dir],getLen(hintnum[dir]) - 1);setS(hintnum[dir], i);board[nextY][nextX] = i;}
			if(solve()) return true;
			for(int dir=0;dir<2;dir++){setLen(hintnum[dir],getLen(hintnum[dir]) + 1);setS(hintnum[dir], i);board[nextY][nextX] = 0;}
		}
	}
	return false;
}

void getCandi(){
	for(int i=2;i<=1024;i+=2){ //Return set
		int sum = 0, len = 0;
		for(int j=1;j<10;j++)if(inSet(i, j)) {sum+=j;len++;}
		for(int j=0;j<=1024;j+=2){ //Mask set
			int masksum = 0, flag = 0;
			for(int k=1;k<10;k++)if(inSet(i, k)&&inSet(j, k)){flag=1;break;}
			if(flag)continue;
			for(int k=1;k<10;k++)if(inSet(j, k)) masksum += k;
			candi[sum + masksum][len][j] = i;
		}
	}
}

void setHintMap(){
	memset(candi, 0, sizeof(candi));
	memset(hintMap, 0, sizeof(hintMap));
	for(int i=0;i<HINT.size();i++){
		int Y = HINT[i].y, X = HINT[i].x, dir = HINT[i].dir, left = 0;
		setSum(i, HINT[i].sum);
		if(dir == 1) Y++; else X++;
		while(Y<N&&X<N&&board[Y][X]!=-1){
			hintMap[Y][X][dir] = i;
			if(dir == 1) Y++; else X++;
			left++;
		}
		setLen(i, left);
	}
	
	getCandi();
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