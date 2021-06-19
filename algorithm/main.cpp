#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int H,W,best,blocksize;
vector<string> board;
vector<vector<pair<int,int>>> blocks;

int max(int a, int b){
	return a>b?a:b;
}

vector<string> rotate(vector<string> block){
	vector<string> ret(block[0].size(), string(block.size(), ' '));
	for(int i=0;i<block.size();i++){
		for(int j=0;j<block[0].size();j++){
			ret[j][block.size()-i-1] = block[i][j];
		}
	}
	return ret;
}
void mkBlocks(vector<string> block){
	blocks.clear();blocks.resize(4);
	for(int r=0;r<4;r++){
		int originX = -1, originY = -1;
		for(int i=0;i<block.size();i++){
			for(int j=0;j<block[0].size();j++){
				if(block[i][j] == '#'){
					if(originY == -1){
						originY = i;originX = j; 
					}
					blocks[r].push_back(make_pair(i-originY, j-originX));
				}
			}
		}
		block = rotate(block);
	}
	blocksize = blocks[0].size();
	sort(blocks.begin(), blocks.end());
	blocks.erase(unique(blocks.begin(), blocks.end()), blocks.end());
}

bool set(int y, int x, int r, int del){
	if(del == 1){
		for(int i=0;i<blocksize;i++){
			int dy = blocks[r][i].first, dx = blocks[r][i].second;
			if(!(y+dy>=0&&y+dy<H&&x+dx>=0&&x+dx<W))return false;
			if(board[y+dy][x+dx] == '#')return false;
		}
		for(int i=0;i<blocksize;i++){
			int dy = blocks[r][i].first, dx = blocks[r][i].second;
			board[y+dy][x+dx] = '#';
		}
	}else{
		for(int i=0;i<blocksize;i++){
			int dy = blocks[r][i].first, dx = blocks[r][i].second;
			board[y+dy][x+dx] = '.';
		}
	}
	return true;
}

void solve(int Y, int X, int num, int last){ //Finds a place to place from left top
	for(int i=Y;i<H;i++){
		for(int j=(i==Y?X:0) ; j<W ; j++){
			if(board[i][j]=='.'){
				for(int r=0;r<blocks.size();r++){
					if(last/blocksize<= best - num)return;
					if(set(i,j,r,1)){
						best = max(best, num + 1);
						solve(i, j+1, num+1, last - blocksize);
						set(i,j,r,0);
					}
				}
				solve(i, j+1, num, last);
				return;
			}
		}
	}
}
void print(){
	for(int r=0;r<blocks.size();r++){
		printf("!%d\n",(int)blocks[r].size());
		for(int i=0;i<blocksize;i++){
			printf("##%d %d\n",blocks[r][i].first, blocks[r][i].second);
		}
	}
}

int main(){
	int T; cin>>T;
	vector<string> block;
	int R,C;
	while(T--){
		block.clear();board.clear();
		cin>>H>>W>>R>>C; string temp;
		for(int i=0;i<H;i++){cin>>temp;board.push_back(temp);}
		for(int j=0;j<R;j++){cin>>temp;block.push_back(temp);}
		mkBlocks(block);best=0;
		int last=0;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(board[i][j] == '.')last ++;
		solve(0,0,0,last);
		cout<<best<<endl;
	}
	return 0;
}