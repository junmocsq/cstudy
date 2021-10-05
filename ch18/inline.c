#include "average.h"
 inline int lmm(int a,int b){
    return (a+b)/2;
}

int main(void){
    int x = 10,y = 20;
    int z=30;
   
    z = average(z,y);
     z = lmm(x,y);
    z +=10;
    return z;
}