#include <stdio.h>
#include <vector>

using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)

int H,W;
int pattern[4][3][2]={
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{0,1},{-1,1}}
};

int set(int r,int x,int y,int del,vector<vector<int>>& board){
    int tx, ty,flag=1;
    FOR(i,3){
        tx=x+pattern[r][i][0];
        ty=y+pattern[r][i][1];
        if(tx<0||tx>=W||ty<0||ty>=H){
            flag=0;
        }else if((board[ty][tx]+=del)>1)flag=0;
    }
    return flag;
}

int solve(vector<vector<int>>& board){
    int x=20,y=20,ret=0;
    FOR(i,H){
        FOR(j,W){
            if(board[i][j]==0){
                x=j;y=i;break;
            }if(x!=20)break;
        }
    }if(x==20)return 1;

    FOR(r,4){
        if(set(r,x,y,1,board))
            ret+=solve(board);
        set(r,x,y,-1,board);
    }
    return ret;
}


int main(){
    int C;char temp[21];
    vector<vector<int>> board(20,vector<int>(20));
    scanf("%d",&C);
    while(C--){
        scanf("%d%d",&H,&W);
        FOR(i,H){scanf("%s",temp);FOR(j,W){if(temp[j]=='.')board[i][j]=0;else board[i][j]=1;}}
        printf("%d\n",solve(board));
    }return 0;
}