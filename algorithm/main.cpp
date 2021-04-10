#include <iostream>
#include <memory.h>

using namespace std;

char board[5][5];char cache[1<<25];
int TRI[4][3][2] = {{{0,0},{1,0},{1,1}}, //ㄱ
                    {{1,0},{1,1},{0,1}},
                    {{0,0},{1,1},{0,1}}, //ㄴ
                    {{0,0},{1,0},{0,1}}};
int BI[2][2][2] = {{{0,0},{1,0}}, //ㅡ
                   {{0,0},{0,1}}}; //ㅣ

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

//1 to possible 0 to impo'
int check(char cur[][5], int x, int y, int type){ //0~3 - triblock 4~5 - biblock
    if(type<=3){
        for(int i=0;i<3;i++){
            int X = x + TRI[type][i][0];
            int Y = y + TRI[type][i][1];
            if(X > 4 || Y > 4) return 0;
            if(cur[X][Y] == '#') return 0;
        }
    }else{
        type -= 4;
        for(int i=0;i<2;i++){
            int X = x + BI[type][i][0];
            int Y = y + BI[type][i][1];
            if(X > 4 || Y > 4) return 0;
            if(cur[X][Y] == '#') return 0;
        }
    }
    return 1;
}
void modify(char cur[][5], int x, int y, int type, int put){
    if(type<=3){
        for(int i=0;i<3;i++){
            int X = x + TRI[type][i][0];
            int Y = y + TRI[type][i][1];
            cur[X][Y] = (put==0?'.':'#');
        }
    }else{
        type -= 4;
        for(int i=0;i<2;i++){
            int X = x + BI[type][i][0];
            int Y = y + BI[type][i][1];
            cur[X][Y] = (put==0?'.':'#');
        }
    }
}

char max(char &a, char &b){
    return a>b?a:b;
}

int opti(char cur[][5]){
    char temp[5][5]; int ret;
    //#2
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            temp[4-j][i] = cur[i][j];
        }
    }
    ret = bton(temp);
    if(cache[ret]!=0)return ret;
    //#3
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            temp[4-i][4-j] = cur[i][j];
        }
    }
    ret = bton(temp);
    if(cache[ret]!=0)return ret;
    //#4
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            temp[j][4-i] = cur[i][j];
        }
    }
    ret = bton(temp);
    if(cache[ret]!=0)return ret;
    return bton(cur);
}

char solve(char cur[][5]){//1 win -1 lose
    char &ret = cache[opti(cur)]; if(ret != 0)return ret;

    //BC
    ret = -1;

    /*printf("\n$$\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%c",cur[i][j]);
        }
        printf("\n");
    }printf("\n$$\n");*/

    for(int y=0; y<5; y++){
        for(int x=0; x<5; x++){
            for(int type=0; type<6; type++){
                if(check(cur, x, y, type)){
                    modify(cur, x, y, type, 1);
                    ret = max(ret, (char)-solve(cur));
                    modify(cur, x, y, type, 0);
                }
            }
        }
    }

    return ret;
}

int main(){
    int C;cin>>C;memset(cache, 0, sizeof(cache));
    while(C--){
        for(int i=0;i<5;i++)scanf("%s",board[i]);
        cout<<((solve(board)==1)?"WINNING\n":"LOSING\n");
    }return 0;
}