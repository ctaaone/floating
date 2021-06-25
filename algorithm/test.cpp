#include <iostream>

using namespace std;

int A = 0;

inline int getA(){return A&0x0000FFFF;}
inline int getB(){return ((A&0xFFFF0000)>>16)&0x0000FFFF;}
inline void setA(char v){A&=0xFFFF0000;A|=v;}
inline void setB(char v){A&=0x0000FFFF;A|=(v<<16);}

int main(){
    setA(1);setB(2);
    printf("%X\n", A);
    cout<<getA()<<" "<<getB()<<endl;
    setA(10);setB(13);
    printf("%X\n", A);
    cout<<getA()<<" "<<getB();
    return 0;
}