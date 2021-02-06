int fastsum(int n){
    if(n==1)return 1;
    if(n%2==1)return fastsum(n-1)+n;
    return (n*n)/4+2*fastsum(n/2);
}