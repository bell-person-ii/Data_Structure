/* 원반 n개를 A에서 C로 이동
원반n-1개를 A에서 B로 이동
큰 원반 1개를 A에서 C로이동
작은 원반 n-1개를 B에서 C로 이동*/


#include <stdio.h>

void hanoi(int num, char from, char by, char to){
    
    if (num==1){
        printf("원반 1을 %c로 이동\n",to);
    }
    
    else{
        hanoi(num-1,from,to,by);
        printf("원반 %d를 %c에서 %c로 이동\n",num,from,to);
        hanoi(num-1,by,from,to);
    }
}


int main(void){
    
    hanoi(5,'A','B','C');

    return 0;
}
