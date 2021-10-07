#include <stdio.h>
#include <ctype.h>

int max(int x,int y);
#define max(x,y) ((x)<(y)?(y):(x))

// cc 21.c && ./a.out
int main(void){

    printf("%d \n",max(3,4));
    return 0 ;
}