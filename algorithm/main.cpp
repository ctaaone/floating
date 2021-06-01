#include <iostream>

using namespace std;


int H,W,R,C;
char board[10][10], piece[10][10], P[4][10][10];

void piece_opti(){
	int xl,xr,yt,yb;
	for(int i=0;i<C;i++){
		xl=i;
		for(int j=0;j<R;j++)if(piece[j][i]=='#')break;
	}
	for(int i=C-1;i>=0;i--){
		xr=i;
		for(int j=0;j<R;j++)if(piece[j][i]=='#')break;
	}
	for(int i=0;i<R;i++){
		yt=i;
		for(int j=0;j<C;j++)if(piece[i][j]=='#')break;
	}
	for(int i=R-1;i>=0;i--){
		yb=i;
		for(int j=0;j<C;j++)if(piece[i][j]=='#')break;
	}
	for(int i=0;i<=yb-yt;i++){
		for(int j=0;j<=xr-xl;j++){
			piece[i][j] = piece[i+yt][j+xl];
		}
	}
	R=yb-yt+1;C=xr-xl+1;
	for(int y=0;y<R;y++){
		for(int x=0;x<C;x++){
			P[0][y][x] = piece[y][x];
			P[2][x][R-y] = piece[y][x];
			P[1][R-y][C-x] = piece[y][x];
			P[3][C-x][y] = piece[y][x];
		}
	}
}

int check(int Y, int X, int r){
	int r=R,c=C;
	if(r>1){r=C;c=R;}
	for(int y=0;y<r;y++){
		for(int x=0;x<c;x++){
			if(P[r][y][x]=='#'&&board[y+Y][x+X]=='#')return 0;
		}
	}
	return 1;
}

int solve(){
	int ret = 0,r=R,c=C;
	for(int r=0;r<4;r++){
		if(r>1){r=C;c=R;}
		for(int y=0;y<=H-R;y++){
			for(int x=1-C;x<=W-C;x++){
				if(check(y,x,r)){
					
				}
			}
		}
	}
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>H>>W>>R>>C;
		for(int i=0;i<H;i++)scanf("%s",board[i]);
		for(int i=0;i<R;i++)scanf("%s",piece[i]);
		piece_opti();
		cout<<solve()<<endl;
	}
	return 0;
}