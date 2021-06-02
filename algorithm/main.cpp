#include <iostream>

using namespace std;


int H,W,R,C,MAX,pN;
char board[10][10], piece[10][10], P[4][10][10];

void piece_opti(){
	int xl,xr,yt,yb,flag=0;
	for(int i=0;i<C;i++){
		xl=i;
		flag=0;
		for(int j=0;j<R;j++)if(piece[j][i]=='#'){flag=1;break;}
		if(flag)break;
	}
	for(int i=C-1;i>=0;i--){
		xr=i;flag=0;
		for(int j=0;j<R;j++)if(piece[j][i]=='#'){flag=1;break;}
		if(flag)break;
	}
	for(int i=0;i<R;i++){
		yt=i;flag=0;
		for(int j=0;j<C;j++)if(piece[i][j]=='#'){flag=1;break;}
		if(flag)break;
	}
	for(int i=R-1;i>=0;i--){
		yb=i;flag=0;
		for(int j=0;j<C;j++)if(piece[i][j]=='#'){flag=1;break;}
		if(flag)break;
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
			P[2][x][R-y-1] = piece[y][x];
			P[1][R-y-1][C-x-1] = piece[y][x];
			P[3][C-x-1][y] = piece[y][x];
		}
	}
}

int check(int Y, int X, int ro){
	int r=R,c=C;
	if(ro>1){r=C;c=R;}
	for(int y=0;y<r;y++){
		for(int x=0;x<c;x++){
			if(P[ro][y][x]=='#'&&board[y+Y][x+X]=='#')return 0;
		}
	}
	return 1;
}
void set(int Y, int X, int ro){
	int r=R,c=C;
	if(ro>1){r=C;c=R;}
	for(int y=0;y<r;y++){
		for(int x=0;x<c;x++){
			if(P[ro][y][x]=='#'){
				if(board[y+Y][x+X]=='#')board[y+Y][x+X] = '.';
				else board[y+Y][x+X] = '#';
			}
		}
	}
}
int getNumber(char B[][10],int r,int c,char ch){
	int ret = 0;
	for(int y=0;y<r;y++){
		for(int x=0;x<c;x++){
			if(B[y][x]==ch)ret++;
		}
	}return ret;
}
void solve(int num){
	int bn = getNumber(board, H, W, '.');
	if(bn/pN+num <= MAX)return;
	int r=R,c=C;
	for(int ro=0;ro<4;ro++){
		if(ro>1){r=C;c=R;}
		for(int y=0;y<=H-r;y++){
			for(int x=0;x<=W-c;x++){
				if(check(y,x,ro)){
					if(num+1>MAX)MAX = num+1;
					set(y,x,ro);
					solve(num+1);
					set(y,x,ro);
				}
			}
		}
	}
}
void pr(){
	int r=R,c=C;
	for(int ro=0;ro<4;ro++){
		if(ro>1){r=C;c=R;}
		for(int y=0;y<r;y++){
			for(int x=0;x<c;x++){
				printf("|\t%c\t|",P[ro][y][x]);
			}cout<<endl;
		}
	}
}

int main(){
	int T;cin>>T;
	while(T--){
		cin>>H>>W>>R>>C;MAX=0;
		for(int i=0;i<H;i++)scanf("%s",board[i]);
		for(int i=0;i<R;i++)scanf("%s",piece[i]);
		pN = getNumber(piece, R, C, '#');
		piece_opti();solve(0);
		cout<<MAX<<endl;
	}
	return 0;
}