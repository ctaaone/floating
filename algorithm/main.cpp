#include <iostream>
#include <vector>
#include <utility>
#include <string>

int max (int a, int b){
	return a>b?a:b;
}

vector<vector<pair<int, int>>> rotations;
int blockSize;

vector<string> rotate(const vector<string> & arr){
	vector<string> ret(arr[0].size, string(arr.size(), ' '));
	for(int i=0;i<arr.size();i++)
		for(int j=0;j<arr[0].size();j++)
			ret[j][arr.size()-i-1] = arr[i][j];
	return ret;
} //Rotating 90degree

void generateRotations(vector<string> block){
	rotations.clear();
	rotations.resize(4);
	for(int rot=0;rot<4;rot++){
		int originY = -1, originX = -1; //Origin coor of the block
		for(int i=0;i<block.size();i++)
			for(int j=0;j<block[i].size();j++)
				if(block[i][j] == '#'){
					if(originY == -1){
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i-originY, j-originX));
				}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()));
	blockSize = rotations[0].size;
}

int boardH, boardW;
vector<string> board;

int covered[10][10];
int best;

bool set(int y, int x, const vector<pair<int, int>>& block, int delta);

void search(int place){
	int y =-1,x=-1;
	for(int i=0 ;i<boardH; i++){
		for(int j=0 ;j<boardW; j++)
			if(covered[i][j] == 0){
				y = i;
				x = j;break;
			}
	if(y != -1)break;
	}
	if(y == -1){best = max(best, placed);return;}

	for(int i=0;i<rotations.size();i++){
		if(set(y,x,rotations[i],1))
			search(placed+1);
		set(y,x,rotations[i],-1);
	}
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}

int solve(){
	best = 0;
	for(int i=0;i<boardH;i++){
		for(int j=0;j<boardW;j++){
			covered[i][j] = (board[i][j] == '#' ? 1:0);
		}
	}
	search(0);
	return best;
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>boardH>>boardW;
		
	}
	return 0;
}