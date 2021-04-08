#include <iostream>
#include <memory.h>

using namespace std;

char board[5][5];int cache[1<<25];
int TRI[4][3][2] = {{{0,0},{1,0},{1,1}}, //ㄱ
                    {{1,0},{1,1},{0,1}},
                    {{0,0},{1,1},{0,1}}, //ㄴ
                    {{0,0},{1,0},{0,1}}};

int bton(char b[][5]){
    int ret=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            ret*=2;
            ret+=(b[i][j]=='.'?0:1);
        }
    }
    return ret;
}

int check(char cur[][5]){
    int canPut;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int f=0;f<4;f++){
                canPut = 1;
                for(int s=0;s<3;s++){
                    if(cur[i+TRI[f][s][0]][j+TRI[f][s][0]] == '#')canPut = 0;
                }
                if(canPut == 1)return 1;
            }
        }
    }
    return 0;
}

int solve(char cur[][5]){//1 win 0 lose
    int &ret = cache[bton(cur)]; if(ret != -1)return ret;
    //BC
    if(check(cur)) return ret = 0;

}

int main(){
    int C;cin>>C;memset(cache, -1, sizeof(cache));
    while(C--){
        for(int i=0;i<5;i++)scanf("%s",board[i]);
        cout<<(solve(board)==1)?"WINNING\n":"LOSING\n";
    }return 0;
}