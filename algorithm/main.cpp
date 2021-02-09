#include <iostream>

using namespace std;

int height[20000],N;

int min(int a,int b){
    return a<b?a:b;
}

int base(int s,int e){//기저사례 처리하기 귀찮아서 뭉탱이로 처리
    int max=0;
    for(int i=s;i<e;i++){
        if(height[i]>max)max=height[i];
    }if(e-s>1)for(int i=s;i<e-1;i++){
        if(min(height[i],height[i+1])*2>max)max=min(height[i],height[i+1])*2;
    }if(e-s>2)if(min(height[s],min(height[s+1],height[s+2]))*3>max)max=min(height[s],min(height[s+1],height[s+2]))*3;
    return max;
}
int getwidth(int index,int height){

}

int solve(int s,int e){//현재 scope에서 좌&우&pivot 포함 사각형 중 가장 큰 놈 넓이 retn [s,e)
    if(e-s<=3)return base(s,e);
    int pivot=s+e;pivot/=2;
    int left=solve(s,pivot);
    int right=solve(pivot+1,e);
    int l=pivot-1;
    int r=pivot+1;
    int max=height[pivot];int width=2,floor=max;
    while(l>=s&&r<e){
        if(height[l]>height[r]){
            if(floor>height[l])floor=height[l];
            l--;
            if(width*floor>max)max=width*floor;
        }else {
            if(floor>height[r])floor=height[r];
            r++;
            if(width*floor>max)max=width*floor;
        }width++;
    }while(l>=s){
        if(floor>height[l])floor=height[l];
        l--;
        if(width*floor>max)max=width*floor;
        width++;
    }while(r<e){
        if(floor>height[r])floor=height[r];
        r++;
        if(width*floor>max)max=width*floor;
        width++;
    }
    if(max<left)max=left;
    if(max<right)max=right;
    return max;
}

int main(){
    int C;
    cin>>C;
    while(C--){
        cin>>N;
        for(int i=0;i<N;i++)cin>>height[i];
        cout<<solve(0,N)<<endl;
    }
    return 0;
}