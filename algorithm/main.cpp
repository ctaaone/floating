#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

<<<<<<< HEAD

int func1(){
	return 1;
}

int main(){
	int (*F)() = func1;
	printf("%p\n",F);
	for(int i=0;i<12;i++)printf("%02X",((unsigned char *)F)[i]);
	//((unsigned char*)F)[5] = (unsigned char)2;
	printf("\n%d", func1());
	return 0;
=======
inline int cell(int y, int x) {return 1<<(5*y+x);}

char cache[1<<25];
vector<int> blocks;

void precal(){
    for(int y=0;y<4;y++){
        for(int x=0;x<4;x++){
            vector<int> cells;
            for(int dy=0;dy<2;dy++)for(int dx=0;dx<2;dx++)cells.push_back(cell(y+dy, x+dx));
            int sqare = cells[0] + cells[1] + cells[2] + cells[3];
            for(int i=0;i<4;i++)blocks.push_back(sqare - cells[i]);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            blocks.push_back(cell(i,j)+cell(i+1,j));
            blocks.push_back(cell(j,i)+cell(j,i+1));
        }
    }
}

int bton(char cur[][5]){
    int ret=0;
    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            ret=(ret<<1);
            if(cur[y][x]=='#')ret++;
        }
    }
    return ret;
}

char solve(int cur){
    char & ret = cache[cur]; if(ret != -1) return ret;
    ret = 0;
    for(int i=0;i<blocks.size();i++){
        if((cur&blocks[i])==0)
            if(!solve(cur|blocks[i])) return ret = 1;
    }
    return ret;
}

int main(){
    int C;cin>>C;memset(cache, -1, sizeof(cache));precal();
    char board[5][5];
    while(C--){
        for(int i=0;i<5;i++)scanf("%s",board[i]);
        cout<<(solve(bton(board))?"WINNING\n":"LOSING\n");
    }
    return 0;
>>>>>>> 44420b498ba5f690ccbd589de569cdfbae9fd79f
}