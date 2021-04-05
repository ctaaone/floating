#include <iostream>
#include <memory.h>


using namespace std;

char board[3][3];
int stat[19683];

int btos(char ** cur){
    int ret=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(cur[i][j] == 'o')ret+=1;
            else if(cur[i][j] == 'x')ret+=2;
            ret*=3;
        }
    }
    return ret;
}
char turn(char ** cur){
    int x=0, o=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(cur[i][j] == 'o')o++;
            else x++;
        }
    }
    if(o==x)return 'x';
    return 'o';
}
int check(char ** cur, char t){
    for(int i=0;i<3;i++){
        if(cur[i][0]==cur[i][1]&&cur[i][1]==cur[i][2]){
            if(cur[i][0]==t)return 1;
            return -1;
        }
    }
    for(int i=0;i<3;i++){
        if(cur[0][i]==cur[1][i]&&cur[1][i]==cur[2][i]){
            if(cur[0][i]==t)return 1;
            return -1;
        }
    }
    if(cur[0][0]==cur[1][1]&&cur[1][1]==cur[2][2]){
            if(cur[0][0]==t)return 1;
            return -1;
    }
    if(cur[0][2]==cur[1][1]&&cur[1][1]==cur[2][0]){
            if(cur[0][2]==t)return 1;
            return -1;
    }
    return 0;
}
int max(int &a, int &b){
    return a>b?a:b;
}

int canWin(char ** cur){
    int st = btos(cur);
    int &ret = stat[st]; if(ret != -2)return ret;
    char t = turn(cur);
    ret = -1;
    int c = check(cur, t);
    if(c != 0)return c;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(cur[i][j]!='.')continue;
            cur[i][j] = t;
            max(canWin(cur), ret);
            cur[i][j] = '.';
        }
    }
    return ret;
}

int main(){
    int C; cin>>C;memset(stat, -2, sizeof(stat));
    while(C--){
        for(int i=0;i<3;i++)scanf("%s",board[i]);


    }
    return 0;
}