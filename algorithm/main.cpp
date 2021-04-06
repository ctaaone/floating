/*#include <iostream>
#include <memory.h>
#include <stdlib.h>


using namespace std;

char board[3][3];
int stat[19683];

int btos(char cur[][3]){
    int ret=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(cur[i][j] == 'o')ret+=1;
            else if(cur[i][j] == 'x')ret+=2;
            ret*=3;
        }
    }
    return ret/3;
}
char turn(char cur[][3]){
    int x=0, o=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(cur[i][j] == '.')continue;
            if(cur[i][j] == 'o')o++;
            else x++;
        }
    }
    if(o==x)return 'x';
    return 'o';
}
int check(char cur[][3], char t){
    for(int i=0;i<3;i++){
        if(cur[i][0]=='.')continue;
        if(cur[i][0]==cur[i][1]&&cur[i][1]==cur[i][2]){
            if(cur[i][0]==t)return 1;
            return -1;
        }
    }
    for(int i=0;i<3;i++){
        if(cur[0][i]=='.')continue;
        if(cur[0][i]==cur[1][i]&&cur[1][i]==cur[2][i]){
            if(cur[0][i]==t)return 1;
            return -1;
        }
    }
    if(cur[1][1]=='.')return 0;
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
int min(int &a, int &b){
    return a<b?a:b;
}

int canWin(char cur[][3]){
    int st = btos(cur);
    int &ret = stat[st]; if(ret != -2)return ret;
    
    char t = turn(cur);
    //printf("$%c\n",t);
    int isTie = 1;
    ret = 1;
    
    int c = check(cur, t);
    //printf("#%d\n",c);
    if(c != 0)return ret = c;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(cur[i][j]!='.')continue;
            isTie = 0;
            cur[i][j] = t;
            ret = min(canWin(cur), ret);
            cur[i][j] = '.';
        }
    }
    ret *= -1;
    if(isTie) return ret = 0;
    return ret;
}

int main(){
    int C; cin>>C;
    for(int i=0;i<(int)(sizeof(stat)/sizeof(int));i++)stat[i] = -2;
    while(C--){
        for(int i=0;i<3;i++)scanf("%s",board[i]);
        int R = canWin(board);
        //printf("%d",R);
        if(R==0) cout<<"TIE"<<endl;
        else{
            if(turn(board)=='o'){
                if(R==1)cout<<"o"<<endl;
                else cout<<"x"<<endl;
            }else{
                if(R==1)cout<<"x"<<endl;
                else cout<<"o"<<endl;
            }
        }

    }
    return 0;
}*/